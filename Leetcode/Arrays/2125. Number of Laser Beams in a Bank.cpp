/*
------------------------------------------------------------
🔗 Problem: 535. Encode and Decode TinyURL
------------------------------------------------------------
This is a companion problem to the **System Design** challenge: *Design TinyURL.*

TinyURL is a URL shortening service where:
- You input a long URL (e.g., https://leetcode.com/problems/design-tinyurl)
- It returns a short URL (e.g., http://tinyurl.com/4e9iAk)

You must design a class that supports the following operations:
1️⃣ `encode(longUrl)` → Converts a long URL into a short URL.
2️⃣ `decode(shortUrl)` → Retrieves the original long URL from the short URL.

There are **no constraints** on how encoding/decoding must be implemented,
as long as decoding returns the correct original URL.

------------------------------------------------------------
📘 Example:
Input:
url = "https://leetcode.com/problems/design-tinyurl"

Output:
"https://leetcode.com/problems/design-tinyurl"

Explanation:
Solution obj;
string tiny = obj.encode(url);
string ans = obj.decode(tiny);
// returns original URL after decoding
------------------------------------------------------------
🔒 Constraints:
- 1 <= url.length <= 10⁴
- The input `url` is guaranteed to be a valid URL.
------------------------------------------------------------
🧠 Intuition:
We can simulate TinyURL using a **hash map**:
- Assign each new URL a unique incremental ID.
- Store the mapping: `id → original URL`.
- Generate a short URL by appending the ID to a base domain.
- To decode, extract the ID from the short URL and retrieve the original.

------------------------------------------------------------
⚙️ Approach:
- Use an `unordered_map<string, string>` for constant-time lookups.
- Maintain an integer counter `id` for unique short codes.
- Short URL format: `http://shorten/{id}`

------------------------------------------------------------
⏱️ Time Complexity:
- Encoding: O(1)
- Decoding: O(1)
📦 Space Complexity: O(n) — for storing URL mappings.
------------------------------------------------------------
*/

class Solution {
public:
    unordered_map<string, string> umap;  // Maps short code → original URL
    int id = 0;                          // Unique ID for each new URL

    // 🔹 Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        string code = to_string(id++);
        umap[code] = longUrl;
        return "http://shorten/" + code;
    }

    // 🔹 Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        string code = shortUrl.substr(shortUrl.find_last_of('/') + 1);
        return umap[code];
    }
};
