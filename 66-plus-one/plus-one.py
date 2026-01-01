class Solution:
  def plusOne(self, digits: list[int]) -> list[int]:
    for a, b in reversed(list(enumerate(digits))):
      if b < 9:
        digits[a] += 1
        return digits
      digits[a] = 0

    return [1] + digits