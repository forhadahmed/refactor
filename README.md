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

SftHoFlowTableMgrSm.tin#234-234,556-345 (~1000 LOC)
SftAgent.tin#234-234,556-345            ( ~230 LOC) 
