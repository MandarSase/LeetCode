from collections import Counter

class Solution:
    def lexPalindromicPermutation(self, s: str, target: str) -> str:
        n = len(s)
        cnt = Counter(s)
        odd_chars = [c for c in cnt if cnt[c] % 2 == 1]

        if n % 2 == 0:
            if odd_chars:
                return ""
            mid_char = ""
        else:
            if len(odd_chars) != 1:
                return ""
            mid_char = odd_chars[0]

        half_counts = [0] * 26
        for c, v in cnt.items():
            half_counts[ord(c) - 97] = v // 2
        h = n // 2

        def counts_of(t):
            arr = [0] * 26
            for ch in t:
                arr[ord(ch) - 97] += 1
            return arr

        # ---- Candidate 1: tight prefix H = target[:h] ----
        target_half = target[:h]
        th_counts = counts_of(target_half)
        if all(th_counts[i] == half_counts[i] for i in range(26)):
            H = target_half
            F = H + mid_char + H[::-1]
            if F > target:
                return F

        # ---- Candidate 2: smallest H strictly greater than target[:h] ----
        remaining = half_counts[:]
        best_break, best_char, best_state = -1, -1, None

        for i in range(h):
            t_idx = ord(target[i]) - 97
            for c in range(t_idx + 1, 26):
                if remaining[c] > 0:
                    best_break, best_char = i, c
                    best_state = remaining[:]
                    break
            if remaining[t_idx] > 0:
                remaining[t_idx] -= 1
            else:
                break  # prefix can't be extended further

        if best_break == -1:
            return ""

        st = best_state[:]
        st[best_char] -= 1
        tail = "".join(chr(97 + c) * st[c] for c in range(26))

        H = target[:best_break] + chr(97 + best_char) + tail
        return H + mid_char + H[::-1]