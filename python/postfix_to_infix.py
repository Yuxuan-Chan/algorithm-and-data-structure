#! python3
# -*- coding: utf-8 -*-
import string

# OPERATORS = ['+', '-', '*', '/', '^']
OPERATORS = {'^': 2, '*': 2, '/': 2, '+': 2, '-': 2}
PRIORITY = {'+': 1, '-': 1, '*': 2, '/': 2, '^': 3}


def is_float(x):
    try:
        a = float(x)
    except ValueError:
        return False
    else:
        return True


def is_int(x):
    try:
        a = float(x)
        b = int(a)
    except ValueError:
        return False
    else:
        return a == b


def is_token_a_number(token):
    # 默认是0到9, you can assume that all operands are single characters
    # 即如果是数字的话，不会大于9
    return is_int(token) or is_float(token)


def is_token_a_letter(token):
    # 默认是a-z或A-Z, you can assume that all operands are single characters
    # 即如果是字母的话，只会是单个字符
    return token in string.ascii_lowercase or token in string.ascii_uppercase


def is_an_operand(item):
    return is_token_a_number(item) or is_token_a_letter(item)


def is_a_binary_operator(token):
    return OPERATORS[token] == 2


def is_an_operator(item):
    operators_key = OPERATORS.keys()

    if item in operators_key:
        return True

    return False


def counter_decrease_for_token(token):
    if is_token_a_number(token):
        return 0

    elif is_token_a_letter(token):
        return 0

    elif is_a_binary_operator(token):
        return -2


def check(formula):
    formula = formula.replace(' ', '')  # 先去除空格, operands and operators may or may not be separated by spaces
    # 即有可能有空格，有可能没有空格，所以进行统一处理，将空格全部去掉
    # print(formula)
    counter = 0
    for token in formula:
        # print(token)
        if not is_an_operand(token) and not is_an_operator(token):
            return False

        counter += counter_decrease_for_token(token)
        # print(counter)

        if counter < 0:
            return False

        counter += 1

    return counter == 1


def postfix_to_infix(formula):
    is_valid = check(formula)

    if is_valid:
        stack = []
        prev_op = None
        for ch in formula:
            if ch not in OPERATORS:
                stack.append(ch)
            else:
                b = stack.pop()
                a = stack.pop()
                if prev_op and len(a) > 1 and PRIORITY[ch] > PRIORITY[prev_op]:
                    # 如果之前的运算符级别较低的话
                    expr = '(' + a + ')' + ch + b
                else:
                    expr = a + ch + b
                stack.append(expr)
                prev_op = ch
        print(stack[-1])
        return stack[-1]
    else:
        print('invalid')
        return 'invalid'


if __name__ == '__main__':
    postfix_to_infix('ab+c/')