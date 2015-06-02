#include<string>
#include<vector>
#include<iterator>
#include"aho_corasick.hpp"

main() {
	typedef typename std::vector<std::string>::const_iterator pat_container_iter;
	typedef typename std::string::const_iterator corpus_iter;
	std::vector<std::string> patterns;
	std::string pat1 = "he";
	std::string pat2 = "she";
	std::string pat3 = "his";
	std::string pat4 = "her";
	std::string haystack = "usher and she he her";
	patterns.push_back(pat1);
	patterns.push_back(pat2);
	patterns.push_back(pat3);
	patterns.push_back(pat4);
	corpus_iter cfirst = haystack.begin();
	corpus_iter clast = haystack.end();
	std::vector<std::pair<corpus_iter, corpus_iter> > output;
	aho_corasick_search<pat_container_iter, corpus_iter, corpus_iter>(cfirst, clast, patterns.begin(), patterns.end(), output);
	for(int i = 0; i < output.size(); i++)
		std::cout<<std::distance(cfirst,std::get<1>(output[i]) )<<'\n';
}

