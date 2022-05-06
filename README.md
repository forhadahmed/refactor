# Introduction

`refactor` is a tool that analyzes source files (C/C++ currently) and identifies blocks of code that appear to be similar.  Code blocks that are similar can be refactored out into common functions or templates *(not a part of this tool)*.

# Identifying Similar Blocks

A block (or "scope") within a source file is code enclosed within braces: `{ ... }`.  

Blocks are heirarchical:
- a block can have multiple "child" block/scopes 
- a block is part of a parent block/scope (unless it is the top-level scope of the file)

![image](https://user-images.githubusercontent.com/2707770/167050904-dd0a1abc-c094-453b-9991-88a63c54e37e.png)

This tool parses all blocks from source files and does a pair-wise comparison among all blocks for "similarity".  This is computed using python's [SequenceMatcher](https://docs.python.org/3/library/difflib.html#sequencematcher-examples) implementation.  A pair of blocks that have a [ratio()](https://docs.python.org/3/library/difflib.html#difflib.SequenceMatcher.ratio) above a certain threshold are considered "similar".

For large input file sets, there can be thousands of code blocks to compare - from small 2-3 liner blocks to large function bodies.  Smaller blocks are discarded for comparison which cuts down the processing time. More options are discussed in the [Usage](#usage) section that can further reduce the number of blocks processed by the tool.

# Usage

```
refactor [options] [files]
```
The output of the tool is an HTML report containing all of the similar blocks (with side-by-side diffs):

![image](https://user-images.githubusercontent.com/2707770/167007824-937948cc-ece8-4c5d-a5b4-7580999e4a53.png)

