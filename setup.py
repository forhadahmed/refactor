#!/usr/bin/env python3
from setuptools import setup

with open("README.md", "r", encoding="utf-8") as f:
    long_description = f.read()

setup(
    name="refactor-tool",
    version="1.0.0",
    author="Forhad Ahmed",
    author_email="ahmed.7449@gmail.com",
    description="Code duplication detector with machine-readable output for AI agents",
    long_description=long_description,
    long_description_content_type="text/markdown",
    url="https://github.com/forhadahmed/refactor",
    project_urls={
        "Bug Tracker": "https://github.com/forhadahmed/refactor/issues",
        "Source Code": "https://github.com/forhadahmed/refactor",
    },
    scripts=["refactor"],
    classifiers=[
        "Development Status :: 5 - Production/Stable",
        "Environment :: Console",
        "Intended Audience :: Developers",
        "License :: OSI Approved :: MIT License",
        "Operating System :: OS Independent",
        "Programming Language :: Python :: 3",
        "Programming Language :: Python :: 3.6",
        "Programming Language :: Python :: 3.7",
        "Programming Language :: Python :: 3.8",
        "Programming Language :: Python :: 3.9",
        "Programming Language :: Python :: 3.10",
        "Programming Language :: Python :: 3.11",
        "Programming Language :: Python :: 3.12",
        "Topic :: Software Development :: Quality Assurance",
        "Topic :: Software Development :: Testing",
        "Topic :: Utilities",
    ],
    keywords=[
        "code-duplication",
        "duplicate-code",
        "refactoring",
        "code-analysis",
        "static-analysis",
        "code-quality",
        "code-clone",
        "ai-agents",
        "automation",
    ],
    python_requires=">=3.6",
    install_requires=[],
)
