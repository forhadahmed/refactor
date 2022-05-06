# Introduction

`refactor` is a tool that analyzes source files (C/C++ currently) and identifies blocks of code that appear to be similar.  

The intended uscases are:
- refactoring similar blocks of code into common functions/templates *(not a part of this tool)*
- finding unintentional mismatches as a result of copy/pasting (and only partially updating) code  

# Implementation

A block (or "scope") within a source file is code enclosed within braces: `{ ... }`.  

Blocks are heirarchical:
- a block can have multiple "child" block/scopes 
- a block is part of a parent block/scope (unless it is the top-level scope of the file)

![image](https://user-images.githubusercontent.com/2707770/167050904-dd0a1abc-c094-453b-9991-88a63c54e37e.png)

This tool parses all blocks from source files and does a pair-wise comparison among all blocks for "similarity".  This is computed using python's [SequenceMatcher](https://docs.python.org/3/library/difflib.html#sequencematcher-examples) implementation.  A pair of blocks that have a [ratio()](https://docs.python.org/3/library/difflib.html#difflib.SequenceMatcher.ratio) above a certain threshold are considered "similar" (default=0.8).

The largest blocks are compared first.  If two blocks are found to be similar, their children are discarded from further comparisons. For example, in the above diagram, if block `#1` is found to be similar to another block (not shown), then blocks `#3`, `#4`, `#5` (subtree for block `#1`) whould not be compared with any other blocks.  Block `#2` sould still be eligible for comparison.   

For large input file sets, there can be thousands of code blocks to compare - from small 2-3 liner blocks to large function bodies.  Smaller blocks are typically discarded for comparison which cuts down the processing time:
- a default minimum block size filter is used which discards many smaller blocks from processing
- two larger blocks found to be similar discards their subtrees (of smaller blocks) from processing


More is discussed in the [Options](#options) section that can further reduce the number of blocks processed by the tool.

# Basic Usage

```
refactor [options] [files]
```
Or:
```
find [filter] | refactor [options]
```
 
Example: 

![usage](https://user-images.githubusercontent.com/2707770/167070282-9bbf69dd-1fe9-4a98-a8bd-4cccf8ce9def.gif)
 

The output of the tool is an HTML report containing the similar blocks found (with side-by-side diffs):

![image](https://user-images.githubusercontent.com/2707770/167007824-937948cc-ece8-4c5d-a5b4-7580999e4a53.png)

# Options

[wip]

# Example Runs

| Description  | Github Link | `refactor` output |
| ------------- | ------------- | -----
| [Linux Kernel Ethernet Drivers](https://github.com/torvalds/linux/tree/master/drivers/net/ethernet)  | https://github.com/torvalds/linux | d  |
| Dear ImGUI: Popular C++ GUI Library  | https://github.com/ocornut/imgui |  d |
| C++ JSON Library |https://github.com/nlohmann/json| d |
