#include "Config.h"

#include <cmath>
#include <iostream>
#include <string>
#include <vector>

#define PRINT

std::ostream& operator<<(std::ostream& os, 
                         const std::vector<std::string>& rhs)
{
  for (const auto& i : rhs)
  {
    os << i << " ";
  }
  os << '\n';

  return os;
}

// space O(m*n) time O(m*n)
std::vector<std::string> LCSS(const std::string& firstStr,
                 const std::string& secondStr)
{
  std::vector<std::string> result;

  const size_t rows = firstStr.size();
  const size_t cols = secondStr.size();

  size_t maxLength = 0;
  std::vector<std::vector<size_t>> matrix(
    rows, std::vector<size_t>(cols, 0));

  for (size_t i = 0; i < rows; ++i)
  {
    for (size_t j = 0; j < cols; ++j)
    {
      if (firstStr[i] == secondStr[j])
      {
        if (i == 0 || j == 0)
        {
          matrix[i][j] = 1;
        } else {
          matrix[i][j] = matrix[i - 1][j - 1] + 1;
        }

        if (matrix[i][j] > maxLength)
        {
          maxLength = matrix[i][j];

          if (result.size() > 1)
          {
            result.clear();
          }
          result.push_back(firstStr.substr(i + 1 - maxLength, maxLength));
        }
        else if (matrix[i][j] == maxLength) 
        {
          result.push_back(firstStr.substr(i + 1 - maxLength, maxLength));
        }
      }
      else
      {
        matrix[i][j] = 0;
      }

    }
  }

#ifdef PRINT
  std::cout << '\n';
  for (auto row : matrix)
  {
    for (auto i : row)
    {
      std::cout << i << " ";
    }
    std::cout << '\n';
  }
  #endif // PRINT

  return result;
}

// space optimized
// space O(min(m, n)) time O(m*n)
std::vector<std::string> LCSS2(const std::string& firstStr,
                 const std::string& secondStr)
{
  std::vector<std::string> result;

  const auto& first = 
    firstStr.size() > secondStr.size() ? firstStr : secondStr;
  const auto& second = 
    firstStr.size() > secondStr.size() ? secondStr : firstStr;

  const size_t rows = first.size();
  const size_t cols = second.size();

  size_t maxLength = 0;
  std::vector<std::vector<size_t>> table(2, std::vector<size_t>(cols, 0));

  for (size_t i = 0; i < rows; ++i)
  {
    for (size_t j = 0; j < cols; ++j)
    {
      if (first[i] == second[j])
      {
        if (i == 0 || j == 0)
        {
          table[i % 2][j] = 1;
        }
        else
        {
          table[i % 2][j] = table[(i + 1) % 2][j - 1] + 1;
        }

        if (table[i % 2][j] > maxLength)
        {
          maxLength = table[i % 2][j];

          if (!result.empty())
          {
            result.clear();
          }
          result.push_back(first.substr(i + 1 - maxLength, maxLength));
        }
        else if (table[i % 2][j] == maxLength) 
        {
          result.push_back(first.substr(i + 1 - maxLength, maxLength));
        }
      }
      else
      {
        table[i % 2][j] = 0;
      }
    }
  }

#ifdef PRINT
  std::cout << '\n';
  for (auto row : table)
  {
    for (auto i : row)
    {
      std::cout << i << " ";
    }
    std::cout << '\n';
  }
#endif // PRINT

  return result;
}

int main(int argc, char *argv[])
{
  if (argc < 2)
  {
    // report version
    std::cout << argv[0] << " Version " << LCSS_VERSION_MAJOR << "." << LCSS_VERSION_MINOR << std::endl;
    std::cout << "Usage: " << argv[0] << " number" << std::endl;
    return 1;
  }

  std::string firstStr = "abs sdfkk kcd";
  std::string secondStr = "kcd ki abss qwe";

  std::cout << "result: " <<  LCSS(firstStr, secondStr) << std::endl;
  std::cout << "result: " <<  LCSS2(firstStr, secondStr) << std::endl;

  return 0;
}
