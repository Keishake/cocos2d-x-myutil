//
//  GyazoUtil.cpp
//
//  Created by Keisuke on 2015/04/17.
//
//

#include "GyazoUtil.h"
#include <curl/curl.h>
#include <sys/stat.h>

USING_NS_CC;
using namespace std;

GyazoUtil::GyazoUtil()
{
    
}

GyazoUtil::~GyazoUtil()
{
    
}

bool GyazoUtil::upload()
{
    std::string filename = "screenshot-for-gyazo.png";
    std::string fullpath = FileUtils::getInstance()->getWritablePath() + filename;
    
    auto size = Director::getInstance()->getWinSize();
    RenderTexture* texture = RenderTexture::create((int)size.width, (int)size.height);
    texture->setPosition(size/2);
    texture->begin();
    Director::getInstance()->getRunningScene()->visit();
    texture->end();
    texture->saveToFile(filename, Image::Format::PNG);
    
    CURL *curl;
    CURLcode res;
    
    struct curl_httppost *formpost=NULL;
    struct curl_httppost *lastptr=NULL;
    struct curl_slist *headerlist=NULL;
    static const char buf[] = "Expect:";
    
    curl_global_init(CURL_GLOBAL_ALL);
    
    /* Fill in the file upload field */
    curl_formadd(&formpost,
                 &lastptr,
                 CURLFORM_COPYNAME, "imagedata",
                 CURLFORM_FILE, fullpath.c_str(),
                 CURLFORM_END);
    
    /* Fill in the filename field */
    curl_formadd(&formpost,
                 &lastptr,
                 CURLFORM_COPYNAME, "access_token",
                 CURLFORM_COPYCONTENTS, "YOUR_ACCESS_TOKEN_HERE",
                 CURLFORM_END);
    
    
    /* Fill in the submit field too, even if this is rarely needed */
    curl_formadd(&formpost,
                 &lastptr,
                 CURLFORM_COPYNAME, "submit",
                 CURLFORM_COPYCONTENTS, "send",
                 CURLFORM_END);
    
    curl = curl_easy_init();
    /* initalize custom header list (stating that Expect: 100-continue is not
     wanted */
    headerlist = curl_slist_append(headerlist, buf);
    if(curl) {
        /* what URL that receives this POST */
        curl_easy_setopt(curl, CURLOPT_URL, "http://upload.gyazo.com/api/upload");
        curl_easy_setopt(curl, CURLOPT_HTTPPOST, formpost);
        
        /* Perform the request, res will get the return code */
        res = curl_easy_perform(curl);
        /* Check for errors */
        if(res != CURLE_OK){
            fprintf(stderr, "curl_easy_perform() failed: %s\n",
                    curl_easy_strerror(res));
            return false;
        }
        
        /* always cleanup */
        curl_easy_cleanup(curl);
        
        /* then cleanup the formpost chain */ 
        curl_formfree(formpost);
        /* free slist */ 
        curl_slist_free_all (headerlist);
        return true;
    }else{
        return false;
    }
}
