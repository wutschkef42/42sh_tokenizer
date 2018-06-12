

# Basic Tokenizer for command-line syntax

## Introduction
This tokenizer is implemented as a finite state machine. It splits command-line
syntax into tokens and prints them on stdout.
The tokens are classified as either WORDS or OPERATORS. No format checking is
done, so an ill-formated token like <<<<<< would pass. To fix this, we will check all
operator tokens on format in a second pass.

## Usage
Simply make and go `./alex "some command-line string"`

## Example
`./alex "find ~/Library/Logs/DiagnosticReports -mindepth 1 -delete > /dev/null||bla"`

word token: find<br/>
word token: ~/Library/Logs/DiagnosticReports<br/>
word token: -mindepth<br/>
word token: 1<br/>
word token: -delete<br/>
operator token: ><br/>
word token: /dev/null<br/>
operator token: ||<br/>
last token: bla<br/>

## Next Steps
The tokenizer must be expanded to handle inhibitors (', ", \\). The tokens must
be stored in a list and hydrated with their specific TOKENTYPE for
interpretation. 
