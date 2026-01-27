#include "bashs.hpp"

namespace GView::Type::BASHS
{
using namespace GView::View::LexicalViewer;

//Keywords
namespace KeywordsType
{
    constexpr uint32 If       = 0;
    constexpr uint32 Then     = 1;
    constexpr uint32 Else     = 2;
    constexpr uint32 Elif     = 3;
    constexpr uint32 Fi       = 4;
    constexpr uint32 For      = 5;
    constexpr uint32 While    = 6;
    constexpr uint32 Until    = 7;
    constexpr uint32 Do       = 8;
    constexpr uint32 Done     = 9;
    constexpr uint32 Case     = 10;
    constexpr uint32 Esac     = 11;
    constexpr uint32 Function = 12;
    constexpr uint32 In       = 13;
    constexpr uint32 Select   = 14;
    constexpr uint32 Time     = 15;
} // namespace KeywordsType

//Built-in commands
namespace BuiltinType
{
    constexpr uint32 Echo     = 0;
    constexpr uint32 Cd       = 1;
    constexpr uint32 Pwd      = 2;
    constexpr uint32 Export   = 3;
    constexpr uint32 Unset    = 4;
    constexpr uint32 Source   = 5;
    constexpr uint32 Exit     = 6;
    constexpr uint32 Return   = 7;
    constexpr uint32 Break    = 8;
    constexpr uint32 Continue = 9;
    constexpr uint32 Read     = 10;
    constexpr uint32 Declare  = 11;
    constexpr uint32 Local    = 12;
    constexpr uint32 Readonly = 13;
} // namespace BuiltinType

namespace CharType
{
    constexpr uint8 Word       = 0;
    constexpr uint8 Number     = 1;
    constexpr uint8 Operator   = 2;
    constexpr uint8 Space      = 3;
    constexpr uint8 Invalid    = 4;
    constexpr uint8 String     = 5;
    constexpr uint8 Comment    = 6;
    constexpr uint8 Variable   = 7;
    constexpr uint8 BlockOpen  = 8;
    constexpr uint8 BlockClose = 9;
    constexpr uint8 Semicolon  = 10;
    constexpr uint8 ExprOpen   = 11;
    constexpr uint8 ExprClose  = 12;
    constexpr uint8 NewLine    = 13;

    uint8 Bash_Groups_IDs[] = { Invalid,  Invalid,  Invalid,  Invalid,   Invalid,  Invalid,    Invalid,  Invalid,  Invalid,  Space,    NewLine,  Invalid,
                                Invalid,  NewLine,  Invalid,  Invalid,   Invalid,  Invalid,    Invalid,  Invalid,  Invalid,  Invalid,  Invalid,  Invalid,
                                Invalid,  Invalid,  Invalid,  Invalid,   Invalid,  Invalid,    Invalid,  Invalid,  Space,    Operator, String,   Comment,
                                Variable, Operator, Operator, String,    ExprOpen, ExprClose,  Operator, Operator, Invalid,  Operator, Word,     Operator,
                                Number,   Number,   Number,   Number,    Number,   Number,     Number,   Number,   Number,   Number,   Invalid,  Semicolon,
                                Operator, Operator, Operator, Invalid,   Invalid,  Word,       Word,     Word,     Word,     Word,     Word,     Word,
                                Word,     Word,     Word,     Word,      Word,     Word,       Word,     Word,     Word,     Word,     Word,     Word,
                                Word,     Word,     Word,     Word,      Word,     Word,       Word,     Invalid,  Operator, Invalid,  Operator, Word,
                                Invalid,  Word,     Word,     Word,      Word,     Word,       Word,     Word,     Word,     Word,     Word,     Word,
                                Word,     Word,     Word,     Word,      Word,     Word,       Word,     Word,     Word,     Word,     Word,     Word,
                                Word,     Word,     Word,     BlockOpen, Operator, BlockClose, Operator, Invalid };

    inline uint32 GetCharType(char16 c)
    {
        if (c < ARRAY_LEN(Bash_Groups_IDs))
            return Bash_Groups_IDs[c];
        return Invalid;
    }
} // namespace CharType

BASHSFile::BASHSFile()
{
}

bool BASHSFile::Update()
{
    return true;
}

bool IsKeyword(const char16* text, uint32 length)
{
    if (length == 2) {
        if (text[0] == 'i' && text[1] == 'f')
            return true;
        if (text[0] == 'f' && text[1] == 'i')
            return true;
        if (text[0] == 'd' && text[1] == 'o')
            return true;
        if (text[0] == 'i' && text[1] == 'n')
            return true;
    } else if (length == 4) {
        if (text[0] == 't' && text[1] == 'h' && text[2] == 'e' && text[3] == 'n')
            return true;
        if (text[0] == 'e' && text[1] == 'l' && text[2] == 's' && text[3] == 'e')
            return true;
        if (text[0] == 'e' && text[1] == 'l' && text[2] == 'i' && text[3] == 'f')
            return true;
        if (text[0] == 'd' && text[1] == 'o' && text[2] == 'n' && text[3] == 'e')
            return true;
        if (text[0] == 'c' && text[1] == 'a' && text[2] == 's' && text[3] == 'e')
            return true;
        if (text[0] == 'e' && text[1] == 's' && text[2] == 'a' && text[3] == 'c')
            return true;
        if (text[0] == 't' && text[1] == 'i' && text[2] == 'm' && text[3] == 'e')
            return true;
    } else if (length == 3) {
        if (text[0] == 'f' && text[1] == 'o' && text[2] == 'r')
            return true;
    } else if (length == 5) {
        if (text[0] == 'w' && text[1] == 'h' && text[2] == 'i' && text[3] == 'l' && text[4] == 'e')
            return true;
        if (text[0] == 'u' && text[1] == 'n' && text[2] == 't' && text[3] == 'i' && text[4] == 'l')
            return true;
    } else if (length == 6) {
        if (text[0] == 's' && text[1] == 'e' && text[2] == 'l' && text[3] == 'e' && text[4] == 'c' && text[5] == 't')
            return true;
    } else if (length == 8) {
        if (text[0] == 'f' && text[1] == 'u' && text[2] == 'n' && text[3] == 'c' && text[4] == 't' && text[5] == 'i' && text[6] == 'o' && text[7] == 'n')
            return true;
    }
    return false;
}

bool IsBuiltin(const char16* text, uint32 length)
{
    if (length == 2) {
        if (text[0] == 'c' && text[1] == 'd')
            return true;
    } else if (length == 3) {
        if (text[0] == 'p' && text[1] == 'w' && text[2] == 'd')
            return true;
    } else if (length == 4) {
        if (text[0] == 'e' && text[1] == 'c' && text[2] == 'h' && text[3] == 'o')
            return true;
        if (text[0] == 'e' && text[1] == 'x' && text[2] == 'i' && text[3] == 't')
            return true;
        if (text[0] == 'r' && text[1] == 'e' && text[2] == 'a' && text[3] == 'd')
            return true;
    } else if (length == 5) {
        if (text[0] == 'u' && text[1] == 'n' && text[2] == 's' && text[3] == 'e' && text[4] == 't')
            return true;
        if (text[0] == 'b' && text[1] == 'r' && text[2] == 'e' && text[3] == 'a' && text[4] == 'k')
            return true;
        if (text[0] == 'l' && text[1] == 'o' && text[2] == 'c' && text[3] == 'a' && text[4] == 'l')
            return true;
    } else if (length == 6) {
        if (text[0] == 'e' && text[1] == 'x' && text[2] == 'p' && text[3] == 'o' && text[4] == 'r' && text[5] == 't')
            return true;
        if (text[0] == 's' && text[1] == 'o' && text[2] == 'u' && text[3] == 'r' && text[4] == 'c' && text[5] == 'e')
            return true;
        if (text[0] == 'r' && text[1] == 'e' && text[2] == 't' && text[3] == 'u' && text[4] == 'r' && text[5] == 'n')
            return true;
    } else if (length == 7) {
        if (text[0] == 'd' && text[1] == 'e' && text[2] == 'c' && text[3] == 'l' && text[4] == 'a' && text[5] == 'r' && text[6] == 'e')
            return true;
    } else if (length == 8) {
        if (text[0] == 'c' && text[1] == 'o' && text[2] == 'n' && text[3] == 't' && text[4] == 'i' && text[5] == 'n' && text[6] == 'u' && text[7] == 'e')
            return true;
        if (text[0] == 'r' && text[1] == 'e' && text[2] == 'a' && text[3] == 'd' && text[4] == 'o' && text[5] == 'n' && text[6] == 'l' && text[7] == 'y')
            return true;
    }
    return false;
}

uint32 BASHSFile::TokenizeWord(const TextParser& text, TokensList& tokenList, uint32 pos)
{
    auto next = text.Parse(pos, [](char16 ch) {
        auto type = CharType::GetCharType(ch);
        return (type == CharType::Word) || (type == CharType::Number);
    });

    auto wordText = text.GetSubString(pos, next);
    auto length   = next - pos;

    TokenColor tokColor   = TokenColor::Word;
    uint32 tokType        = TokenType::Word;
    TokenAlignament align = TokenAlignament::AddSpaceBefore;
    TokenFlags tokenFlags = TokenFlags::None;

    //Check if it s a keyword
    if (IsKeyword(wordText.data(), length)) {
        tokType    = TokenType::Keyword;
        tokColor   = TokenColor::Keyword;
        align      = TokenAlignament::AddSpaceBefore | TokenAlignament::AddSpaceAfter;
        tokenFlags = TokenFlags::DisableSimilaritySearch;
    }
    //Check if it s a builtin command
    else if (IsBuiltin(wordText.data(), length)) {
        tokType    = TokenType::Command;
        tokColor   = TokenColor::Keyword2;
        tokenFlags = TokenFlags::DisableSimilaritySearch;
    }

    tokenList.Add(tokType, pos, next, tokColor, TokenDataType::None, align, tokenFlags);
    return next;
}

uint32 BASHSFile::TokenizeVariable(const TextParser& text, TokensList& tokenList, uint32 pos)
{
    //$variable sau ${variable}
    auto next = pos + 1;

    if (text[next] == '{') {
        //${variable} format - parse until }
        next = text.ParseUntilNextCharacterAfterText(next, "}", false);
    } else {
        //$variable format
        next = text.Parse(next, [](char16 ch) { return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9') || ch == '_'; });
    }

    tokenList.Add(TokenType::Variable, pos, next, TokenColor::Constant, TokenDataType::None, TokenAlignament::None, TokenFlags::None);
    return next;
}

uint32 BASHSFile::TokenizeOperator(const TextParser& text, TokensList& tokenList, uint32 pos)
{
    auto ch               = text[pos];
    auto next             = pos + 1;
    uint32 tokType        = TokenType::Operator;
    TokenColor tokColor   = TokenColor::Operator;
    TokenAlignament align = TokenAlignament::AddSpaceBefore | TokenAlignament::AddSpaceAfter;

    //Check composite op
    auto ch2 = text[next];

    if (ch == '|') {
        if (ch2 == '|') {
            next++;
            tokType = TokenType::Operator; // ||
        } else {
            tokType = TokenType::Pipe; // |
        }
    } else if (ch == '&') {
        if (ch2 == '&') {
            next++;
            tokType = TokenType::Operator; // &&
        } else {
            tokType = TokenType::Operator; // &
        }
    } else if (ch == '>') {
        if (ch2 == '>') {
            next++;
        }
        tokType = TokenType::Redirect; // > sau >>
    } else if (ch == '<') {
        if (ch2 == '<') {
            next++;
        }
        tokType = TokenType::Redirect; // < sau <<
    }

    tokenList.Add(tokType, pos, next, tokColor, TokenDataType::None, align, TokenFlags::DisableSimilaritySearch);
    return next;
}

void BASHSFile::BuildBlocks(SyntaxManager& syntax)
{
    //Build blocks pentru structuri ca { ... }
    TokenIndexStack stBlocks;
    auto len = syntax.tokens.Len();

    for (auto index = 0U; index < len; index++) {
        auto typeID = syntax.tokens[index].GetTypeID(TokenType::None);
        switch (typeID) {
        case TokenType::BlockOpen:
            stBlocks.Push(index);
            break;
        case TokenType::BlockClose:
            syntax.blocks.Add(stBlocks.Pop(), index, BlockAlignament::ParentBlockWithIndent, BlockFlags::EndMarker);
            break;
        }
    }
}

void BASHSFile::Tokenize(const TextParser& text, TokensList& tokenList, BlocksList& blocks)
{
    Tokenize(0, text.Len(), text, tokenList, blocks);
}

void BASHSFile::Tokenize(uint32 start, uint32 end, const TextParser& text, TokensList& tokenList, BlocksList& blocks)
{
    auto idx = start;

    while (idx < end) {
        auto ch   = text[idx];
        auto type = CharType::GetCharType(ch);

        switch (type) {
        case CharType::Space:
            //Only parse spaces and tabs, not newlines
            idx = text.ParseSpace(idx, SpaceType::SpaceAndTabs);
            break;

        case CharType::NewLine: {
            //Handle newlines explicitly
            auto next = idx + 1;
            //Handle CRLF or LFCR combinations
            if (next < end) {
                auto nextCh = text[next];
                if ((ch == '\r' && nextCh == '\n') || (ch == '\n' && nextCh == '\r')) {
                    next++;
                }
            }
            
            //Ensure the last token ends with a newline
            auto lastToken = tokenList.GetLastToken();
            if (lastToken.IsValid()) {
                lastToken.UpdateAlignament(TokenAlignament::NewLineAfter);
            }
            
            idx = next;
            break;
        }

        case CharType::Comment: {
            //Shebang
            if (idx == start && ch == '#' && text[idx + 1] == '!') {
                auto next = text.ParseUntilEndOfLine(idx);
                tokenList.Add(
                      TokenType::Shebang,
                      idx,
                      next,
                      TokenColor::Preprocesor,
                      TokenDataType::MetaInformation,
                      TokenAlignament::NewLineAfter,
                      TokenFlags::DisableSimilaritySearch);
                idx = next;
            } else {
                //Comment
                auto next = text.ParseUntilEndOfLine(idx);
                tokenList.Add(
                      TokenType::Comment,
                      idx,
                      next,
                      TokenColor::Comment,
                      TokenDataType::MetaInformation,
                      TokenAlignament::AddSpaceBefore | TokenAlignament::NewLineAfter,
                      TokenFlags::DisableSimilaritySearch);
                idx = next;
            }
            break;
        }

        case CharType::String: {
            auto next = text.ParseString(idx, StringFormat::DoubleQuotes | StringFormat::SingleQuotes | StringFormat::AllowEscapeSequences);
            tokenList.Add(TokenType::String, idx, next, TokenColor::String, TokenDataType::String);
            idx = next;
            break;
        }

        case CharType::Variable:
            idx = TokenizeVariable(text, tokenList, idx);
            break;

        case CharType::Number: {
            auto next = text.ParseNumber(idx);
            tokenList.Add(TokenType::Number, idx, next, TokenColor::Number, TokenDataType::Number);
            idx = next;
            break;
        }

        case CharType::Word:
            idx = TokenizeWord(text, tokenList, idx);
            break;

        case CharType::Operator:
            idx = TokenizeOperator(text, tokenList, idx);
            break;

        case CharType::BlockOpen:
            tokenList.Add(
                  TokenType::BlockOpen,
                  idx,
                  idx + 1,
                  TokenColor::Operator,
                  TokenDataType::None,
                  TokenAlignament::AddSpaceBefore | TokenAlignament::NewLineAfter,
                  TokenFlags::DisableSimilaritySearch);
            idx++;
            break;

        case CharType::BlockClose:
            tokenList.Add(
                  TokenType::BlockClose,
                  idx,
                  idx + 1,
                  TokenColor::Operator,
                  TokenDataType::None,
                  TokenAlignament::StartsOnNewLine | TokenAlignament::NewLineAfter,
                  TokenFlags::DisableSimilaritySearch);
            idx++;
            break;

        case CharType::Semicolon:
            tokenList.Add(
                  TokenType::Semicolon,
                  idx,
                  idx + 1,
                  TokenColor::Operator,
                  TokenDataType::None,
                  TokenAlignament::AfterPreviousToken | TokenAlignament::NewLineAfter,
                  TokenFlags::DisableSimilaritySearch);
            idx++;
            break;

        case CharType::ExprOpen:
            tokenList.Add(
                  TokenType::ExpressionOpen,
                  idx,
                  idx + 1,
                  TokenColor::Operator,
                  TokenDataType::None,
                  TokenAlignament::None,
                  TokenFlags::DisableSimilaritySearch);
            idx++;
            break;

        case CharType::ExprClose:
            tokenList.Add(
                  TokenType::ExpressionClose,
                  idx,
                  idx + 1,
                  TokenColor::Operator,
                  TokenDataType::None,
                  TokenAlignament::None,
                  TokenFlags::DisableSimilaritySearch);
            idx++;
            break;

        default: {
            auto next = text.ParseSameGroupID(idx, CharType::GetCharType);
            tokenList.Add(TokenType::Word, idx, next, TokenColor::Word).SetError("Invalid character sequence");
            idx = next;
            break;
        }
        }
    }
}

void BASHSFile::PreprocessText(TextEditor& editor)
{
    //No preprocess
}

void BASHSFile::GetTokenIDStringRepresentation(uint32 id, AppCUI::Utils::String& str)
{
    switch (id & 0xFFFFFFFF) {
    case TokenType::None:
        str.Set("Unknown/Error");
        break;
    case TokenType::Comment:
        str.Set("Comment");
        break;
    case TokenType::String:
        str.Set("String");
        break;
    case TokenType::Variable:
        str.Set("Variable");
        break;
    case TokenType::Command:
        str.Set("Command");
        break;
    case TokenType::Keyword:
        str.Set("Keyword");
        break;
    case TokenType::Number:
        str.Set("Number");
        break;
    case TokenType::Operator:
        str.Set("Operator");
        break;
    case TokenType::Pipe:
        str.Set("Pipe");
        break;
    case TokenType::Redirect:
        str.Set("Redirect");
        break;
    case TokenType::BlockOpen:
        str.Set("Block (open)");
        break;
    case TokenType::BlockClose:
        str.Set("Block (close)");
        break;
    case TokenType::Semicolon:
        str.Set("Semicolon");
        break;
    case TokenType::Word:
        str.Set("Word");
        break;
    case TokenType::Shebang:
        str.Set("Shebang");
        break;
    case TokenType::Substitution:
        str.Set("Command Substitution");
        break;
    case TokenType::ExpressionOpen:
        str.Set("Expression (open)");
        break;
    case TokenType::ExpressionClose:
        str.Set("Expression (close)");
        break;
    }
}

void BASHSFile::AnalyzeText(SyntaxManager& syntax)
{
    syntax.tokens.ResetLastTokenID(TokenType::None);
    Tokenize(syntax.text, syntax.tokens, syntax.blocks);
    BuildBlocks(syntax);
}

bool BASHSFile::StringToContent(std::u16string_view string, AppCUI::Utils::UnicodeStringBuilder& result)
{
    return TextParser::ExtractContentFromString(string, result, StringFormat::All);
}

bool BASHSFile::ContentToString(std::u16string_view content, AppCUI::Utils::UnicodeStringBuilder& result)
{
    NOT_IMPLEMENTED(false);
}

} // namespace GView::Type::BASHS
