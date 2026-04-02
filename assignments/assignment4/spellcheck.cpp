#include "spellcheck.h"

#include <algorithm>
#include <cctype>
#include <iostream>
#include <iterator>
#include <numeric>
#include <ranges>
#include <set>
#include <vector>

template <typename Iterator, typename UnaryPred>
std::vector<Iterator> find_all(Iterator begin, Iterator end, UnaryPred pred);

Corpus tokenize(std::string& source) {
    auto iterators = find_all(source.begin(), source.end(), [] (unsigned char ch) {
        return std::isspace(ch);
    });

    auto create_token = [&source] (auto& it1, auto& it2) {
        return Token(source, it1, it2);    
    };

    Corpus tokens;
    auto d_first = std::inserter(tokens, tokens.end()); 
    std::transform(iterators.begin(), --iterators.end(), ++iterators.begin(), d_first, create_token);
   
    std::erase_if(tokens, [] (const auto& token) {
        return token.content.empty();
    });

    return tokens;
}

std::set<Misspelling> spellcheck(const Corpus& source, const Dictionary& dictionary) {
    namespace rv= std::ranges::views;
    
    auto view =
        source | rv::filter([&] (const auto& token) { 
            return !dictionary.contains(token.content); 
        }) | rv::transform([&] (const auto& token) {
            auto view = 
                dictionary | rv::filter([&] (const auto& word) {
                    return levenshtein(token.content, word) == 1;
                });
            std::set<std::string> suggestions(view.begin(), view.end());
            return Misspelling {token, suggestions}; 
        }) | rv::filter([&] (const auto& misspelling) { 
            return !misspelling.suggestions.empty(); 
        });

    return std::set<Misspelling>(view.begin(), view.end());
};



/* Helper methods */
#include "utils.cpp"
