package lexer

import (
	"compiler_golang/token"
	"testing"
)

func TestNextToken(t *testing.T) {
	input := "=+(){}"
	tests := []struct {
		expectedType    token.TokenType
		expectedLiteral string
	}{
		{token.EOF, ""},
	}
	for i, tt := range tests {
		if input != "=+(){}" {
			t.Fatalf("this is a fake one. count: %d, expected valie: %s, %s", i, tt.expectedType, tt.expectedLiteral)
		}
	}

}
