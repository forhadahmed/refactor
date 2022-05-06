# Introduction

`refactor` is a tool that analyzes source files (C/C++ currently) and identifies blocks of code that appear to be similar.  

The intended uscases are:
- refactoring similar blocks of code into common functions or templates *(not a part of this tool)*
- finding unintentional mismatches in similar blocks as a result of copy/pasting code 

# Identifying Similar Blocks

A block (or "scope") within a source file is code enclosed within braces: `{ ... }`.  

Blocks are heirarchical:
- a block can have multiple "child" block/scopes 
- a block is part of a parent block/scope (unless it is the top-level scope of the file)

![image](https://user-images.githubusercontent.com/2707770/167050904-dd0a1abc-c094-453b-9991-88a63c54e37e.png)

This tool parses all blocks from source files and does a pair-wise comparison among all blocks for "similarity".  This is computed using python's [SequenceMatcher](https://docs.python.org/3/library/difflib.html#sequencematcher-examples) implementation.  A pair of blocks that have a [ratio()](https://docs.python.org/3/library/difflib.html#difflib.SequenceMatcher.ratio) above a certain threshold are considered "similar".

The largest blocks are compared first.  If two blocks are found to be similar, their children are discarded from further comparisons. For example, in the above diagram, if block `#1` is found to be similar to another block (not shown), then blocks `#3`, `#4`, `#5` (subtree for block `#1`) whould not be compared with any other blocks.  Block `#2` sould still be eligible for comparison.   

For large input file sets, there can be thousands of code blocks to compare - from small 2-3 liner blocks to large function bodies.  Smaller blocks are typically discarded for comparison which cuts down the processing time:
- a default minimum block size filter is used which discards many smaller blocks from processing
- two larger blocks found to be similar discards their subtrees (of smaller blocks) from processing


More is discussed in the [Options](#options) section that can further reduce the number of blocks processed by the tool.

# Basic Usage

```
refactor [options] [files]
```
The output of the tool is an HTML report containing all of the similar blocks (with side-by-side diffs):

![image](https://user-images.githubusercontent.com/2707770/167007824-937948cc-ece8-4c5d-a5b4-7580999e4a53.png)

# Options

null
