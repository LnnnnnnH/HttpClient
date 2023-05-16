#pragma once
#include <string>

namespace utility
{

	inline std::wstring UTF8_To_UTF16(const std::string &source)
	{
        std::wstring_convert<std::codecvt_utf8_utf16<wchar_t>> converter;
        return converter.from_bytes(source);
	}

	inline std::string UTF16_To_UTF8(const std::wstring &source)
	{
        std::wstring_convert<std::codecvt_utf8_utf16<wchar_t>> converter;
        return converter.to_bytes(source);
	}


	inline std::wstring GBK_To_UTF16(const std::string &source)
	{
        std::wstring_convert<std::codecvt_utf8<wchar_t>> converter;
        return converter.from_bytes(source);
	}

	inline std::string UTF16_To_GBK(const std::wstring &source)
	{
        std::wstring_convert<std::codecvt_utf8<wchar_t>> converter;
        return converter.to_bytes(source);
	}

	inline std::string GBK_To_UTF8(const std::string &source)
	{
        std::wstring_convert<std::codecvt_utf8<wchar_t>> conv1;
        std::wstring wtemp = conv1.from_bytes(source);
        std::wstring_convert<std::codecvt_utf8_utf16<wchar_t>> conv2;
        return conv2.to_bytes(wtemp);
	}

	inline std::string UTF8_To_GBK(const std::string &source)
	{
        std::wstring_convert<std::codecvt_utf8_utf16<wchar_t>> conv1;
        std::wstring wtemp = conv1.from_bytes(source);
        std::wstring_convert<std::codecvt_utf8<wchar_t>> conv2;
        return conv2.to_bytes(wtemp);
	}
}