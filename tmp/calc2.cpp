#include <iostream>
#include <string>
#include <vector>

std::vector<std::string> processexp(const std::string &sexp);

int main()
{

        std::string sexp;

        std::getline(std::cin, sexp);
        std::cout << sexp << std::endl;

        std::vector<std::string> svret = processexp(sexp);

		std::cout << "result:" << std::endl;
        for (const auto &i : svret) {
                std:: cout << i << std::endl;
        }
        return 0;
}

std::vector<std::string> processexp(const std::string &sexp)
{
        std::vector<std::string> svec;
        std::vector<std::string> destsvec;
        std::vector<std::string> midsvec;

        std::string read;
        char c;

        for (std::string::size_type i = 0; i < sexp.size(); i++) {
                c = sexp[i];
                switch (c) {
                case '*':
					std::cout << "got *, read=[" << read << "]" << std::endl;
                        {
                        if (!read.empty()) {
                                svec.push_back(read);
                                read.clear();
                        }
                        svec.emplace_back(1, c);
                        }
                        break;
                case '(':
					std::cout << "got (, [" << read << "]" << std::endl;
                        {
                        std::string::size_type m, n, p1, p2;
                        m = i;
                        while (true) {
                                m += 1;
                                p1 = sexp.find_first_of('(', m);
                                p2 = sexp.find_first_of(')', m);
                                if (p1 != std::string::npos && p1 < p2) {
                                        m = p2;
                                        continue;
                                }
                                n = p2;
                                break;
                        }
                        std::string subexp = sexp.substr(i+1, n - i - 1);
                        std::vector<std::string> sv = processexp(subexp);
                        if (i > 1 && sexp[i-1] != '*'
                                && n + 1 < sexp.size() && sexp[n+1] == '*') {
                                midsvec = sv;
                                i = n;
                                break;
                        }

                        std::string bfexp;
                        for (const auto &e : svec) {
                                bfexp += e;
                        }
                        svec.clear();
                        std::vector<std::string> desttemp{midsvec};
                        midsvec.clear();
                        for (const auto &e : sv) {
                                if (!desttemp.empty()) {
                                        for (const auto &e2 : desttemp) {
                                                auto e3 = e2 + bfexp + e;
                                                midsvec.push_back(e3);
                                        }
                                } else {
                                        midsvec.push_back(bfexp+e);
                                }
                        }
                        if (n + 1 < sexp.size() && sexp[n+1] == '*') {
#if 0
                                for (const auto &e : destsvec) {
                                        std::cout << "|<<<" << e << "|";
                                }
                                std::cout << std::endl;
#endif
                        } else {
                                destsvec.insert(destsvec.end(), midsvec.begin(), midsvec.end());
                                midsvec.clear();
                        }
                        i = n;
                        }
                        break;
                case '+':
					std::cout << "got +, [" << read << "]" << std::endl;
                        {
                        if (!read.empty()) {
                                svec.push_back(read);
                        }
                        std::string all;
                        for (const auto &e : svec) {
                                all += e;
                        }

                        if (!all.empty()) {
                                std::vector<std::string> desttemp{midsvec};
                                midsvec.clear();
                                if (!desttemp.empty()) {
                                        for (const auto &e2 : desttemp) {
                                                auto e3 = e2 + all;
                                                destsvec.push_back(e3);
                                        }
                                } else {
                                        destsvec.push_back(all);
                                }
                        }
                        svec.clear();
                        read.clear();
                        }
                        break;
                default:
                        read += c;
                        break;
                }
        }
		std::cout << "last read [" << read << "]" << std::endl;
        if (!read.empty()) {
                svec.push_back(read);
        }
        std::string all;
        for (const auto &e : svec) {
                all += e;
        }
        if (!all.empty()) {
                std::vector<std::string> desttemp{midsvec};
                midsvec.clear();
                if (!desttemp.empty()) {
                        for (const auto &e2 : desttemp) {
                                auto e3 = e2 + all;
                                destsvec.push_back(e3);
                        }
                } else {
                        destsvec.push_back(all);
                }
        }

        return destsvec;
}
