<details>
  <summary>Click to see full Math Library details</summary>
  
  This calculator uses the standard `math.h` library and requires the `-lm` linker flag.
</details>
For a professional C project like your **Scientific Calculator**, you want a README that is clean, scannable, and looks great on GitHub.

Here are the essential Markdown (MD) tags and a structured template you can copy and paste.

---

## 1. The Essential MD Tags

| Element | Tag | Use Case |
| :--- | :--- | :--- |
| **H1 Header** | `# Title` | Project Name |
| **H2 Header** | `## Header` | Sections (Installation, Usage) |
| **Bold** | `**text**` | Emphasizing key requirements |
| **Inline Code** | `` `text` `` | Commands or file names (e.g., `make`) |
| **Code Block** | ` ```c ` ... ` ``` ` | Syntax highlighting for code snippets |
| **Bullet Points** | `* Item` | Feature lists |
| **Link** | `[Text](URL)` | Linking to documentation or your profile |
| **Images** | `![Alt](URL)` | Screenshots or project diagrams |

---

## 2. Recommended README Template
You can copy this directly into your `README.md` and fill in the details.
```markdown
# Scientific Calculator

A lightweight, terminal-based scientific calculator built entirely in **C**. This project focuses on high-performance math operations and clean modular architecture.

## 🚀 Features
* **Basic Arithmetic:** Addition, Subtraction, Multiplication, Division.
* **Advanced Math:** Trigonometry (sin, cos, tan), Logarithms, and Square Roots.
* **Memory Functions:** Store and recall previous results.
* **Modular Design:** Easily extensible for new mathematical functions.

## 🛠️ Installation & Build
This project uses a `Makefile` for easy compilation.

### Prerequisites
* A C compiler (GCC, Clang, or MinGW)
* GNU Make

### Building the Project
1. Clone the repository:
   ```bash
   git clone https://github.com/Dani-uC/Scientific_calculator.git
   cd Scientific_calculator