# ece309_harness

ECE 309 Project 1: An LLM Mini-Harness in C via Vibe Coding 

Project Overview & Goals 
In this foundational project, you will build a minimal LLM agent harness in C. An agent 
harness acts as the bridge between an LLM and the operating system, managing inputs, 
context boundaries, tool execution, etc. 

Instead of writing every line manually, you will utilize vibe coding—steering an AI assistant 
through clear, structured prompts to generate the C codebase. Do not panic if you feel that  
you don’t write a line of code in this project. For this project, you are the architect, and the 
AI is your junior developer. Your job is to write a crystal-clear specification, feed it to an AI 
(like ChatGPT, Claude, or Gemini), and verify that the generated code actually works. 

By completing this project, you will: 
- Understand the architectural role of a harness in an LLM agent system. 
- Practice Specification Driven Development (SDD) by writing rigorous technical 
requirements before instructing the AI to generate code. 
- Gain experience managing and verifying AI-assisted coding workflows. 

Implementation Requirements 
Your harness must be written in standard C and compile successfully in a POSIX 
environment. 
1. Core Loop: Implement a terminal-based loop that captures user input, passes it to 
a mock model function (which mimics an LLM), and outputs the simulated 
response. Note that the purpose of the mock model is that you don’t need call the 
LLM APIs. 
2. Context Management: Allocate and manage memory safely to store a minimal 
conversation history (e.g., the last 5 turns) 
3. Tool execution: calls a tool to execute functions such as mathematical calculation 
that an LLM is not designed for. 
4. Vibe Coding Log: Document the architectural rules and prompts you used to 
generate the C code, demonstrating your application of SDD principles. 
5. AI-Generated Testing: Instruct your AI assistant to write a separate testing script 
that validates your harness's state management and checks for basic memory 
leaks.
