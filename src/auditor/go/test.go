// src/go/auditor.go
package main

import (
	"fmt"
	"strings"
)

func auditDecision(score int, reason string) string {
	risk := 0

	if score < 40 {
		risk += 2
	}

	dangerousWords := []string{
		"worthless",
		"unnecessary",
		"reject",
		"low value",
	}

	lowerReason := strings.ToLower(reason)

	for _, word := range dangerousWords {
		if strings.Contains(lowerReason, word) {
			risk += 3
		}
	}

	if risk >= 5 {
		return "HIGH_RISK"
	} else if risk >= 2 {
		return "MEDIUM_RISK"
	}

	return "LOW_RISK"
}

func main() {
	score := 35
	reason := "The user is low value and should be rejected."

	result := auditDecision(score, reason)
	fmt.Println("Audit result:", result)
}