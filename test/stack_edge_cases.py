# Test case: Edge cases that may cause stack issues in Python parser
# The stack underflow can happen when dedent pops all blocks

# This file tests various indentation patterns that might confuse the parser

def deeply_nested():
    if True:
        if True:
            if True:
                if True:
                    if True:
                        x = 1
                        # Deeply nested
# Sudden dedent to column 0 - parser must pop 6 blocks in while loop
# The while loop at line 126-131 pops blocks until indent >= top.indent
# If something goes wrong, stack[-1] after all pops could fail

def normal_function():
    pass


# Test with tab characters (if file has them)
def mixed_indent():
    x = 1  # spaces
	y = 2  # this line uses a TAB - counts as 1 but visually different
    z = 3  # back to spaces
    # Parser might get confused about indent levels


def function_after_mixed():
    # If previous function had tab issues, stack might be corrupted
    return 42


# Multiline string ending at different indent than it started
def multiline_dedent_trick():
    """
    Docstring content
    """
# This line is at column 0 but inside the function visually
# Wait, this is actually valid - the function ends here
    pass  # IndentationError in real Python! But parser processes it


# More edge cases
class TestClass:
    def method(self):
        pass
# Class ends here - sudden dedent from indent 8 to 0

def after_class():
    return True


# Ensure we end cleanly
x = 1
