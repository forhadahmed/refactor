# refactor

[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)
[![Python 3.6+](https://img.shields.io/badge/python-3.6+-blue.svg)](https://www.python.org/downloads/)

**A fast, zero-dependency duplicate code detector and code clone finder.** Analyzes source files across C, C++, Python, JavaScript, Java, Go, and other languages to identify similar code blocks for refactoring and code quality improvement.

## Features

- **Multi-language support** - Works with any bracket-based or indentation-based language
- **Machine-readable output** - JSON output mode for integration with AI agents and automated refactoring pipelines
- **Zero dependencies** - Single Python script, no external packages required
- **HTML reports** - Visual side-by-side diffs with syntax highlighting
- **Smart filtering** - Compares similarly-named files first, skips small blocks, prunes subtrees
- **Scales to large codebases** - Tested on Linux kernel, Bitcoin, Protobuf, and other major projects

## Use Cases

- **Refactoring** - Identify duplicate code blocks to extract into common functions or templates
- **Code review** - Find copy-paste bugs where code was duplicated but only partially updated
- **Technical debt** - Measure and reduce code duplication across your codebase
- **AI-assisted refactoring** - Feed machine-readable output to LLM agents for automated code improvements

*[The Impact of Duplicate Code](https://levelup.gitconnected.com/the-impact-of-duplicate-code-31c0bceab831)*

## Installation

### Direct Download (Recommended)

```bash
curl -O https://raw.githubusercontent.com/forhadahmed/refactor/main/refactor
chmod +x refactor
sudo mv refactor /usr/local/bin/
```

### From Source

```bash
git clone https://github.com/forhadahmed/refactor.git
cd refactor
chmod +x refactor
./refactor --help
```

## Quick Start

```bash
refactor [options] [files]
```

Or pipe files via stdin:

```bash
find src/ -name "*.cpp" | refactor
```

### Example

![usage](https://user-images.githubusercontent.com/2707770/167070282-9bbf69dd-1fe9-4a98-a8bd-4cccf8ce9def.gif)

By default, outputs a colorized side-by-side diff to the terminal. Use `--html` for a visual report:

![image](https://user-images.githubusercontent.com/2707770/167007824-937948cc-ece8-4c5d-a5b4-7580999e4a53.png)

## Agentic Workflows & AI Integration

`refactor` is designed for **machine-readable output**, making it ideal for AI-powered code refactoring pipelines:

```bash
# JSON output for programmatic consumption
refactor --json src/*.py

# Pipe to LLM agents for automated refactoring suggestions
refactor --json src/ | your-ai-agent --task "refactor duplicates"
```

The JSON output includes:
- File paths and line numbers for each duplicate pair
- Similarity scores between code blocks
- The actual code content for both blocks

This enables AI coding assistants and autonomous agents to:
1. **Discover** code duplication automatically
2. **Analyze** the similarity patterns
3. **Generate** refactored code with common abstractions
4. **Apply** changes programmatically

Perfect for integration with tools like Claude Code, Cursor, Aider, and other AI coding agents.

## How It Works

A block (or "scope") within a source file is code enclosed within brackets `{ ... }` or within an indent level (Python).

Blocks are hierarchical:
- A block can have multiple child blocks/scopes
- A block is part of a parent block/scope (unless it is the top-level scope)

![image](https://user-images.githubusercontent.com/2707770/167050904-dd0a1abc-c094-453b-9991-88a63c54e37e.png)

The tool parses all blocks from source files and does pairwise comparison for "similarity" using Python's [SequenceMatcher](https://docs.python.org/3/library/difflib.html#sequencematcher-examples). Blocks with a [ratio()](https://docs.python.org/3/library/difflib.html#difflib.SequenceMatcher.ratio) above the threshold (default=0.8) are considered similar.

**Optimizations:**
- Largest blocks are compared first
- If two blocks are similar, their child subtrees are pruned from further comparison
- Blocks from differently-named files are skipped by default
- Minimum block size filter eliminates noise from small code fragments

## Options

| Option | Description | Default |
|--------|-------------|---------|
| `--min-block-size` | Minimum block size in characters | 1500 |
| `--max-block-diff` | Maximum length difference between compared blocks | 500 |
| `--all-indents` | Compare blocks across different indent levels | off |
| `--all-files` | Compare blocks across all files (not just similarly-named) | off |
| `--json` | Output results in JSON format for machine consumption | off |
| `-o, --output` | HTML output file | `report-<pid>.html` |

## Examples on Popular Repositories

| Project | Repository | Results |
|:--------|:-----------|:--------|
| Linux Kernel Ethernet Drivers | [torvalds/linux](https://github.com/torvalds/linux) | [drivers.html](https://rawcdn.githack.com/forhadahmed/refactor/main/examples/drivers.html) (~400 similar blocks) |
| C++ JSON Library | [nlohmann/json](https://github.com/nlohmann/json) | [json.html](https://rawcdn.githack.com/forhadahmed/refactor/main/examples/json.html) (~350 similar blocks) |
| Bitcoin + Dogecoin | [bitcoin/bitcoin](https://github.com/bitcoin/bitcoin) | [crypto.html](https://rawcdn.githack.com/forhadahmed/refactor/main/examples/crypto.html) (~270 similar blocks) |
| Go BGP Implementation | [osrg/gobgp](https://github.com/osrg/gobgp) | [gobgp.html](https://rawcdn.githack.com/forhadahmed/refactor/main/examples/gobgp.html) (~250 similar blocks) |
| Google Protobuf | [protocolbuffers/protobuf](https://github.com/protocolbuffers/protobuf) | [protobuf.html](https://rawcdn.githack.com/forhadahmed/refactor/main/examples/protobuf.html) (~215 similar blocks) |
| Dear ImGui | [ocornut/imgui](https://github.com/ocornut/imgui) | [imgui.html](https://rawcdn.githack.com/forhadahmed/refactor/main/examples/imgui.html) (~30 similar blocks) |

**Interesting find:** [Dogecoin](https://github.com/dogecoin/dogecoin) and [Bitcoin](https://github.com/bitcoin/bitcoin) share massive code duplication since Dogecoin is a fork. A common library would clean things up significantly!

## License

MIT License - see [LICENSE](LICENSE) for details.
