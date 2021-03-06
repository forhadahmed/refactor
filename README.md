# Introduction

`refactor` is a tool that analyzes source files (most programming languages: C/C++/JS/Python/Java/Go/etc...) and identifies blocks of code that appear to be similar.  

The intended uscases are:
- refactoring similar blocks of code into common functions/templates *(not a part of this tool)*
- finding unintentional mismatches as a result of copy/pasting (and only partially updating) code  

*[The Impact of Duplicate Code](https://levelup.gitconnected.com/the-impact-of-duplicate-code-31c0bceab831)*

# Implementation

A block (or "scope") within a source file is code enclosed within brackets: `{ ... }` or within an indent level (python).  

Blocks are heirarchical:
- a block can have multiple "child" block/scopes 
- a block is part of a parent block/scope (unless it is the top-level scope of the file)

![image](https://user-images.githubusercontent.com/2707770/167050904-dd0a1abc-c094-453b-9991-88a63c54e37e.png)

This tool parses all blocks from source files and does a pair-wise comparison among blocks for "similarity".  This is computed using python's [SequenceMatcher](https://docs.python.org/3/library/difflib.html#sequencematcher-examples) implementation.  A pair of blocks that have a [ratio()](https://docs.python.org/3/library/difflib.html#difflib.SequenceMatcher.ratio) above a certain threshold are considered "similar" (default=0.8).

The largest blocks are compared first.  A block that is a descendent of another block will not be compared with the parent block.  For example, in the above diagram, blocks `#1`/`#3` and `#1`/`#5` will not be compared.  

Also, if two blocks are found to be similar, their children are discarded from further comparisons: if block `#1` is similar to another block (not shown), then blocks `#3`, `#4`, `#5` (subtree for block `#1`) will not be compared with any other blocks.  Block `#2` will still be eligible for comparison.   

For large input file sets, there can be thousands of code blocks to compare - from small 2-3 liner blocks to large function bodies.  Smaller blocks are typically discarded for comparison which cuts down the processing time:
- a default minimum block size filter is used which discards many smaller blocks from processing
- two larger blocks found to be similar discards their subtrees (of smaller blocks) from processing


More is discussed in the [Options](#options) section that can further reduce the number of blocks processed by the tool.

# Basic Usage

Download the `refactor` script from this repository (no external dependencies) and install in `$PATH`. To Run:  

```
refactor [options] [files]
```
Or:
```
find [filter] | refactor [options]
```
 
Example: 

![usage](https://user-images.githubusercontent.com/2707770/167070282-9bbf69dd-1fe9-4a98-a8bd-4cccf8ce9def.gif)
 

The output of the tool is an [HTML report](#examples) containing the similar blocks found (with side-by-side diffs):

![image](https://user-images.githubusercontent.com/2707770/167007824-937948cc-ece8-4c5d-a5b4-7580999e4a53.png)

# Options

- `--min-block-size` Minimum block size/length in characters (default=1500).  Blocks that are smaller than this threshold are not considered for comparison against any other block
- `--max-block-diff` Maximum length diff between two blocks in characters (default=500).  Two blocks that differ in length more than this amount are not considered for comparison against each other.  For example, a block of length 2K chars and another block of length 3K chars will not be compared for similarity by default (a length difference that large means they have no chance of being similar)
- `--all-levels` By default, only blocks in the *same level* of hierarchy are considered for comparison.  For example, in the [Implementation](#implementation) section, blocks `#1`/`#2` are compared and blocks `#3`/`#4` are compared.  Blocks `#2`/`#3` *are not* compared by default. This option enables comparisons across different levels of the tree (more time consuming)
- `--all-files` In most cases, similar blocks come either from one source file (two blocks within the same file have similar code) or from two source files that are similarly named (with small variations in the name). By default, this tool *does not* compare two blocks coming from two source files that are named very differently:  For example:

   - `linux/net/ipv4/udp.c` and `linux/net/ipv6/udp.c` (blocks in these files are eligible for comparison)
   - `linux/net/ipv4/netlink.c` and `linux/net/ipv6/mcast.c` (blocks in these files are not eligible for comarison)

  This option enables comparisons across all files (more time consuming)
- `-o/--output` HTML output file (by default, the tool produces `report-<pid>.html`)

# Examples

Some random example runs from large (and popular) repositories on GitHub. 

| Description  | Github Link | `refactor` output |
| :-- | :-- | :--
| [Linux Kernel Ethernet Drivers](https://github.com/torvalds/linux/tree/master/drivers/net/ethernet)  | [torvalds/linux](https://github.com/torvalds/linux) | [drivers.html](https://rawcdn.githack.com/forhadahmed/refactor/main/examples/drivers.html) (~400 similar blocks) |
| C++ JSON Library | [nlohmann/json](https://github.com/nlohmann/json) | [json.html](https://rawcdn.githack.com/forhadahmed/refactor/main/examples/json.html) (~350 similar blocks) |
| Bitcoin/Dogecoin `--all-files` | [bitcoin/bitcoin](https://github.com/bitcoin/bitcoin) [dogecoin/dogecoin](https://github.com/dogecoin/dogecoin) |  [crypto.html](https://rawcdn.githack.com/forhadahmed/refactor/main/examples/crypto.html) (~270 similar blocks) |     
| Go BGP Implementation | [osrg/gobgp](https://github.com/osrg/gobgp) |  [gobgp.html](https://rawcdn.githack.com/forhadahmed/refactor/main/examples/gobgp.html) (~250 similar blocks) |
| Google Protobuf Library  | [protocolbuffers/protobuf](https://github.com/protocolbuffers/protobuf) |  [protobuf.html](https://rawcdn.githack.com/forhadahmed/refactor/main/examples/protobuf.html) (~215 similar blocks) |
| Dear ImGUI: C++ GUI Library  | [ocornut/imgui](https://github.com/ocornut/imgui) |  [imgui.html](https://rawcdn.githack.com/forhadahmed/refactor/main/examples/imgui.html) (~30 similar blocks) |


Interesting find: [dogecoin](https://github.com/dogecoin/dogecoin) and [bitcoin](https://github.com/bitcoin/bitcoin) could use some major refactoring since the latter is a fork with some tweaks! A common library would clean things up quite a bit...  

