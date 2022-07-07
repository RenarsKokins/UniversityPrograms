/*********************************************************
Failâ lvfriendly.h failâ aprakstîtâs funkcijas atrisina problçmas ar
latvieðu valodas simbolu ievadi un izvadi no konsoles C++ programmâs,
pârveidojot ievadîtos konsolç simbolus no CP775 kodçjuma
uz WINDOWS-1257 un veicot pretçjo procesu simbolus izvadot.
Versija: 5.0 pielâgota C++14 (Uldis Straujums, 2018)
Autors: Çriks Gopaks (versija 4.0, 21/02/2012).
*********************************************************/

#ifndef TRANSLATOR_H_INCLUDED
#define TRANSLATOR_H_INCLUDED

#include <cstdio>
#include <cstring>
#include <iostream>

void Output (const char *s);

const unsigned char From775_To1257[256] = {
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	195, 252, 233, 226, 228, 236, 229, 227, 249, 231, 170, 186, 238, 202, 196, 197,
	201, 191, 175, 244, 246, 204, 162, 218, 250, 214, 220, 184, 163, 168, 215, 164,
	194, 206, 243, 221, 253, 234, 148, 166, 169, 174, 172, 189, 188, 217, 171, 187,
	0, 0, 0, 0, 0, 192, 200, 198, 203, 0, 0, 0, 0, 193, 208, 0,
	0, 0, 0, 0, 0, 0, 216, 219, 0, 0, 0, 0, 0, 0, 0, 222,
	224, 232, 230, 235, 225, 240, 248, 251, 254, 0, 0, 0, 0, 0, 0, 0,
	211, 223, 212, 209, 245, 213, 181, 241, 205, 237, 207, 239, 242, 199, 210, 146,
	173, 177, 147, 190, 182, 167, 247, 132, 176, 0, 183, 185, 179, 178, 0, 160};

const unsigned char From1257_To775[256] = {
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 247, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 239, 242, 166, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	255, 0, 150, 156, 159, 0, 167, 245, 157, 168, 138, 174, 170, 240, 169, 146,
	248, 241, 253, 252, 0, 230, 244, 250, 155, 251, 139, 175, 172, 171, 243, 145,
	181, 189, 160, 128, 142, 143, 183, 237, 182, 144, 141, 184, 149, 232, 161, 234,
	190, 227, 238, 224, 226, 229, 153, 158, 198, 173, 151, 199, 154, 163, 207, 225,
	208, 212, 131, 135, 132, 134, 210, 137, 209, 130, 165, 211, 133, 233, 140, 235,
	213, 231, 236, 162, 147, 228, 148, 246, 214, 136, 152, 215, 129, 164, 216, 0};

std::istream & operator >> (std::istream& in, std::string &s)
{
	std::operator>>(in, s);
	if (&in == &std::cin)
	{
		int sz = s.size();
		for (int i = 0; i < sz; i++)
			if (From775_To1257[(unsigned char)s[i]] > 0)
				s[i] = From775_To1257[(unsigned char)s[i]];
	}
	return in;
}

std::istream & operator >> (std::istream& in, char *s)
{
	std::operator>>(in, s);
	if (&in == &std::cin)
	{
		int sz = strlen(s);
		for (int i = 0; i < sz; i++)
			if (From775_To1257[(unsigned char)s[i]] > 0)
				s[i] = From775_To1257[(unsigned char)s[i]];
	}
	return in;
}

std::ostream & operator << (std::ostream& out, const std::string &s)
{
    if (&out == &std::cout) Output(s.c_str());
    else std::operator<<(out, s);
    return out;
}

std::ostream & operator << (std::ostream& out, const char *s)
{
    if (&out == &std::cout) Output(s);
    else std::operator<<(out, s);
    return out;
}

void Output (const char *s)
{
    int sz = strlen(s);
    unsigned char c;
    for (int i = 0; i < sz; i++)
    {
        c = s[i];
        if (From1257_To775[c] > 0) printf("%c", From1257_To775[c]);
        else printf("%c", c);
    }
}
#endif
