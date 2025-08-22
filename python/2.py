check = [51, 52, 53, 54, 55, 56, 57, 58, 59, 51, 60, 61, 62, 54, 63, 64, 67, 64, 67, 68, 56, 69]

# 将整数列表转换为ASCII字符列表
result_chars = [chr(value) for value in check]

# 将ASCII字符列表组合成字符串
result_string = ''.join(result_chars)

print(result_string)
