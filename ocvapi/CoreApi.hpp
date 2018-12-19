#pragma once

#include <string>

#ifndef _MSC_VER
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wdocumentation"
#endif
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#ifndef _MSC_VER
#pragma GCC diagnostic pop
#endif

class CCoreApi
{
public:
    CCoreApi() = default;
    ~CCoreApi() = default;

    CCoreApi(CCoreApi&) = delete;
    CCoreApi(CCoreApi&&) = delete;
    CCoreApi& operator= (const CCoreApi&) = delete;
    CCoreApi& operator= (const CCoreApi&&) = delete;

public:
    static std::string OpencvVersion() { return CV_VERSION; }
};
