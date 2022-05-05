# Introduction

`refactor` is a tool that analyzes a source tree (C/C++ currently) and identifies blocks of code that appear to be similar.  Code blocks that are similar can be refactored out into common functions or templates *(not a part of this tool)*.

# Identifying Similar Blocks

A block (or "scope") within a source file is code enclosed within braces: `{ .. some code .. }`.  

Blocks are heirarchical:
- a block can have multiple "child" block/scopes 
- a block is part of a parent block/scope (unless it is the top-level scope of the file)

[ graphic ]

This tool scans the input source files and extracts large blocks of code that appear to be similar.  

# Usage

```
refactor <files>
```
```
refactor linux/include/*.h
```

![image](https://user-images.githubusercontent.com/2707770/166866061-813dc145-f263-4477-9e88-bbc7a98d1df6.png)

