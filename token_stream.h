#ifndef TOKEN_STREAM_H
#define TOKEN_STREAM_H

#include <string>


static constexpr char quit = 'q';
static constexpr char print = ';';
static constexpr char number = '8';
static constexpr char name = 'a';
static constexpr char let = 'L';

static const std::string declkey = "let";


struct Token
{
  char kind;
  double value;
  std::string name;

  Token (char ch)
    : kind{ ch }, value{ 0 }
  { }

  Token (char ch, double val)
    : kind{ ch }, value{ val }
  { }

  Token (char ch, std::string s)
    : kind{ ch }, name{ s }
  { }
};


class Token_stream
{
  bool full{ false };
  Token buffer{ '\0' };

public:
  Token_stream () { }

  Token get ();
  void putback (Token t);

  void ignore (char);
};


extern Token_stream ts;

#endif