#include <string.h>
// from "http://www.drdobbs.com/architecture-and-design/matching-wildcards-an-empirical-way-to-t/240169123"
// This function compares text strings, one of which can have wildcards 
// ('*' or '?').
//
bool WildTextCompare(
		char *pTameText,   // A string without wildcards
		char *pWildText    // A (potentially) corresponding string with wildcards
		)
{
	// These two values are set when we observe a wildcard character.  They 
	// represent the locations, in the two strings, from which we start once 
	// we've observed it.
	//
	char *pTameBookmark = (char *) 0;
	char *pWildBookmark = (char *) 0;

	// Walk the text strings one character at a time.
	while (1)
	{
		// How do you match a unique text string?
		if (*pWildText == '*')
		{
			// Easy: unique up on it!
			while (*(++pWildText) == '*')
			{
			}                          // "xy" matches "x**y"

			if (!*pWildText)
			{
				return true;           // "x" matches "*"
			}

			if (*pWildText != '?')
			{
				// Fast-forward to next possible match.
				while (*pTameText != *pWildText)
				{
					if (!(*(++pTameText)))
						return false;  // "x" doesn't match "*y*"
				}
			}

			pWildBookmark = pWildText;
			pTameBookmark = pTameText;
		}
		else if (*pTameText != *pWildText && *pWildText != '?')
		{
			// Got a non-match.  If we've set our bookmarks, back up to one 
			// or both of them and retry.
			//
			if (pWildBookmark)
			{
				if (pWildText != pWildBookmark)
				{
					pWildText = pWildBookmark;

					if (*pTameText != *pWildText)
					{
						// Don't go this far back again.
						pTameText = ++pTameBookmark;
						continue;      // "xy" matches "*y"
					}
					else
					{
						pWildText++;
					}
				}

				if (*pTameText)
				{
					pTameText++;
					continue;          // "mississippi" matches "*sip*"
				}
			}

			return false;              // "xy" doesn't match "x"
		}

		pTameText++;
		pWildText++;

		// How do you match a tame text string?
		if (!*pTameText)
		{
			// The tame way: unique up on it!
			while (*pWildText == '*')
			{
				pWildText++;           // "x" matches "x*"
			}

			if (!*pWildText)
			{
				return true;           // "x" matches "x"
			}

			return false;              // "x" doesn't match "xy"
		}
	}
}
