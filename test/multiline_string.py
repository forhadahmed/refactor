# Test case: Multiline strings cause parser to detect false block boundaries
# The parser doesn't track """ or ''' state, so indentation inside
# multiline strings creates phantom blocks

def function_with_docstring():
    """
    This is a docstring.
    It has multiple lines.
        This line is indented - parser sees this as a new block!
        More indented content.
    Back to normal indent - parser sees this as dedent!
    """
    x = 1
    y = 2
    return x + y


def function_with_multiline_string():
    sql = """
        SELECT *
        FROM users
        WHERE id = 1
            AND name = 'test'
        ORDER BY created_at
    """
    # Parser is now confused about indentation level
    # The dedent from """ to this comment looks like block end
    return sql


def function_with_triple_single_quotes():
    text = '''
    Line 1
        Indented line - new block to parser
            Double indented
        Back one level - dedent
    Back to base
    '''
    # What indent level does parser think we're at?
    result = text.strip()
    return result


class MyClass:
    """Class docstring
    with multiple lines
        and varying indentation
    that confuses the parser
    """

    def method_one(self):
        """Method docstring"""
        return 1

    def method_two(self):
        long_string = """
            This content
                has indentation
            that varies
        """
        # Parser block tracking is now wrong
        if True:
            print("Are we at right level?")
        return long_string
