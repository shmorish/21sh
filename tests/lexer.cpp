extern "C" {
#include "lexer.h"
#include "ft_dlist.h"
}

#include <format>
#include <string>
#include <vector>

#include "CppUTest/TestHarness.h"
#include "CppUTest/UtestMacros.h"

/*
 * Helper functions
 */

using token_pair = std::pair<t_token_type, const char *>;

static t_dlist *create_token_list(std::vector<token_pair> tokens) {
  t_dlist head;
  head.next = nullptr;
  t_dlist *cur = &head;
  t_token *token;

  for (auto [type, value] : tokens) {
    token = lx_token_new(type, value, strlen(value));
    ft_dlstadd_back(&cur, ft_dlstnew(token));
  }
  return (head.next);
}

static void EQUAL_TOKEN(t_token *expected, t_token *actual) {
  const std::string diff =
      std::format("\nexpected: type: {} len: {}, str: {}", int(expected->type),
                  expected->len, expected->str) +
      std::format("\nactual: type: {}, len: {}, str: {}", int(actual->type),
                  actual->len, actual->str);

  CHECK_EQUAL_TEXT(expected->type, actual->type, diff.c_str());
  CHECK_EQUAL_TEXT(expected->len, actual->len, diff.c_str());
  STRNCMP_EQUAL_TEXT(expected->str, actual->str, expected->len, diff.c_str());
}

static void EQUAL_TOKEN_LIST(t_dlist *expected, t_dlist *actual) {
  CHECK_EQUAL_TEXT(ft_dlstsize(expected), ft_dlstsize(actual), "size mismatch");
  while (expected && actual) {
    EQUAL_TOKEN((t_token *)expected->content, (t_token *)actual->content);
    expected = expected->next;
    actual = actual->next;
  }
  CHECK_EQUAL(expected, actual);
}

/*
 * Test cases
 */
TEST_GROUP(LexerTestGroup){};

TEST(LexerTestGroup, SingleWord) {
  t_dlist *expected;
  t_dlist *actual;

  actual = tokenize("hello");
  expected = create_token_list({{TK_WORD, "hello"}, {TK_EOF, ""}});
  EQUAL_TOKEN_LIST(expected, actual);
}

TEST(LexerTestGroup, MultipleWords) {
  t_dlist *expected;
  t_dlist *actual;

  actual = tokenize("   hello  \t world  \t");
  expected =
      create_token_list({{TK_WORD, "hello"}, {TK_WORD, "world"}, {TK_EOF, ""}});
  EQUAL_TOKEN_LIST(expected, actual);
}

TEST(LexerTestGroup, MetaCharacters) {
  t_dlist *expected;
  t_dlist *actual;

  actual = tokenize("`$(;|||&&(){} \t");
  expected = create_token_list({{TK_RSVD, "`"},
                                {TK_RSVD, "$("},
                                {TK_RSVD, ";"},
                                {TK_RSVD, "||"},
                                {TK_RSVD, "|"},
                                {TK_RSVD, "&&"},
                                {TK_RSVD, "("},
                                {TK_RSVD, ")"},
                                {TK_RSVD, "{"},
                                {TK_RSVD, "}"},
                                {TK_EOF, ""}});
  EQUAL_TOKEN_LIST(expected, actual);
}

TEST(LexerTestGroup, SingleQuotedString) {
  t_dlist *expected;
  t_dlist *actual;

  actual = tokenize("'hello'");
  expected = create_token_list({{TK_WORD, "'hello'"}, {TK_EOF, ""}});
  EQUAL_TOKEN_LIST(expected, actual);
}

TEST(LexerTestGroup, DoubleQuotedString) {
  t_dlist *expected;
  t_dlist *actual;

  actual = tokenize("\"hello\"");
  expected = create_token_list({{TK_WORD, "\"hello\""}, {TK_EOF, ""}});
  EQUAL_TOKEN_LIST(expected, actual);
}

TEST(LexerTestGroup, MixedQuotedString) {
  t_dlist *expected;
  t_dlist *actual;

  actual = tokenize("'hello\"world'");
  expected = create_token_list({{TK_WORD, "'hello\"world'"}, {TK_EOF, ""}});
  EQUAL_TOKEN_LIST(expected, actual);
}
