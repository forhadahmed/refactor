# Introduction

`refactor` is a tool that analyzes source files (C/C++ currently) and identifies blocks of code that appear to be similar.  Code blocks that are similar can be refactored out into common functions or templates *(not a part of this tool)*.

# Identifying Similar Blocks

A block (or "scope") within a source file is code enclosed within braces: `{ ... }`.  

Blocks are heirarchical:
- a block can have multiple "child" block/scopes 
- a block is part of a parent block/scope (unless it is the top-level scope of the file)

![image](https://user-images.githubusercontent.com/2707770/167048235-a321cad7-6831-4c40-9f41-385f0b7ce5fe.png)

This tool scans the input source files and extracts large blocks of code that appear to be similar.  

# Usage

```
refactor <files>
```

<a href="https://asciinema.org/a/5LhAJLx39kKRFO6xduFpmoJ9s" target="_blank"><img src="https://asciinema.org/a/5LhAJLx39kKRFO6xduFpmoJ9s.svg" /></a>

![image](https://user-images.githubusercontent.com/2707770/167007824-937948cc-ece8-4c5d-a5b4-7580999e4a53.png)

