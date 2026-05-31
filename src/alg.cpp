// Copyright 2021 NNTU-CS
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <cctype>

#include "bst.h"

void makeTree(BST<std::string>& tree, const char* filename) {
  std::ifstream file(filename);

  if (!file)
    return;

  std::string word;
  char ch;

  while (file.get(ch)) {
    if ((ch >= 'A' && ch <= 'Z') ||
        (ch >= 'a' && ch <= 'z')) {
      word += static_cast<char>(std::tolower(ch));
    } else {
      if (!word.empty()) {
        tree.insert(word);
        word.clear();
      }
    }
  }

  if (!word.empty())
    tree.insert(word);

  file.close();
}

void printFreq(BST<std::string>& tree) {
  std::vector<std::pair<std::string, int>> words;

  tree.getWords(words);

  std::sort(words.begin(), words.end(),
    [](const auto& a, const auto& b) {
      return a.second > b.second;
    });

  std::ofstream fout("result/freq.txt");

  for (const auto& p : words) {
    std::cout << p.first << " " << p.second << std::endl;

    if (fout)
      fout << p.first << " " << p.second << std::endl;
  }

  fout.close();
}
