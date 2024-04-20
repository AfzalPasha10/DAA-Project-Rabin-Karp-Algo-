def rabin_karp(text, pattern):
    text_length = len(text)
    pattern_length = len(pattern)
    prime = 101  # Prime number for hashing

    # Calculate the hash value for the pattern and the first window of the text
    pattern_hash = sum(ord(pattern[i]) * pow(prime, i) for i in range(pattern_length))
    text_hash = sum(ord(text[i]) * pow(prime, i) for i in range(pattern_length))

    # Iterate through the text to find the pattern
    for i in range(text_length - pattern_length + 1):
        if pattern_hash == text_hash and text[i:i + pattern_length] == pattern:
            return i  # Pattern found at index i

        # Update the hash value for the next window
        if i < text_length - pattern_length:
            text_hash = (text_hash - ord(text[i])) / prime
            text_hash = (text_hash * prime + ord(text[i + pattern_length])) % prime

    return -1  # Pattern not found in text

text = "abcdefghijk"
pattern = "abc"

index = rabin_karp(text, pattern)
if index != -1:
    print(f"Pattern '{pattern}' found in text '{text}' at index {index}")
else:
    print(f"Pattern '{pattern}' not found in text '{text}'")