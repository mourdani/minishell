<p align="center">
    <h1 align="center">MINISHELL</h1>
</p>
<p align="center">
    <em>Simplify Commands, Maximize Efficiency-Minishell Power!</em>
</p>
<p align="center">
	<img src="https://img.shields.io/github/license/mourdani/minishell?style=flat&color=0080ff" alt="license">
	<img src="https://img.shields.io/github/last-commit/mourdani/minishell?style=flat&logo=git&logoColor=white&color=0080ff" alt="last-commit">
	<img src="https://img.shields.io/github/languages/top/mourdani/minishell?style=flat&color=0080ff" alt="repo-top-language">
	<img src="https://img.shields.io/github/languages/count/mourdani/minishell?style=flat&color=0080ff" alt="repo-language-count">
<p>
<p align="center">
		<em>Developed with the software and tools below.</em>
</p>
<p align="center">
	<img src="https://img.shields.io/badge/C-A8B9CC.svg?style=flat&logo=C&logoColor=black" alt="C">
	<img src="https://img.shields.io/badge/GitHub%20Actions-2088FF.svg?style=flat&logo=GitHub-Actions&logoColor=white" alt="GitHub%20Actions">
</p>
<hr>

##  Overview

This project involves the development of a simple shell, providing users with the ability to execute executables from different paths and handle arguments and options similar to the bash shell environment.
Project Description
Minishell is a software project that challenges students to rewrite a basic shell, offering functionalities akin to popular shells like bash. By working on this project, students gain hands-on experience in shell scripting and command-line interface development.

---


##  Repository Structure

```sh
└── minishell/
    ├── Makefile
    ├── inc
    │   └── minishell.h
    └── src
        ├── bin
        │   └── ft_bin.c
        ├── builtin
        │   ├── ft_cd.c
        │   ├── ft_echo.c
        │   ├── ft_env.c
        │   ├── ft_export.c
        │   ├── ft_pwd.c
        │   ├── ft_read_token_list.c
        │   └── ft_unset.c
        ├── gnl
        │   ├── get_next_line.c
        │   ├── get_next_line_bis.c
        │   └── get_next_line_utils.c
        ├── init
        │   ├── ft_init_data.c
        │   ├── ft_init_token.c
        │   └── ft_init_var.c
        ├── libft
        │   ├── .github
        │   │   └── workflows
        │   │       └── norminette.yml
        │   ├── .gitignore
        │   ├── .vscode
        │   │   └── settings.json
        │   ├── Makefile
        │   ├── includes
        │   │   ├── get_next_line.h
        │   │   └── libft.h
        │   └── sources
        │       ├── ft_abs.c
        │       ├── ft_abs_d.c
        │       ├── ft_abs_f.c
        │       ├── ft_atoi.c
        │       ├── ft_aux_handle_minus_sign_li.c
        │       ├── ft_bzero.c
        │       ├── ft_calloc.c
        │       ├── ft_clamp_d.c
        │       ├── ft_count_chars_i.c
        │       ├── ft_count_digits.c
        │       ├── ft_count_digits_hex_ui.c
        │       ├── ft_count_digits_hex_ul.c
        │       ├── ft_count_digits_i.c
        │       ├── ft_count_digits_ui.c
        │       ├── ft_div_mod.c
        │       ├── ft_div_mod_i.c
        │       ├── ft_factorial.c
        │       ├── ft_fibonacci.c
        │       ├── ft_i_to_buffer.c
        │       ├── ft_is_a_b.c
        │       ├── ft_is_decimal_char.c
        │       ├── ft_is_plus_or_minus.c
        │       ├── ft_is_valid_base.c
        │       ├── ft_is_whitespace.c
        │       ├── ft_isalnum.c
        │       ├── ft_isalpha.c
        │       ├── ft_isascii.c
        │       ├── ft_isdigit.c
        │       ├── ft_islower.c
        │       ├── ft_isprint.c
        │       ├── ft_isupper.c
        │       ├── ft_itoa.c
        │       ├── ft_lstadd_back.c
        │       ├── ft_lstadd_front.c
        │       ├── ft_lstclear.c
        │       ├── ft_lstdelone.c
        │       ├── ft_lstiter.c
        │       ├── ft_lstlast.c
        │       ├── ft_lstmap.c
        │       ├── ft_lstnew.c
        │       ├── ft_lstsize.c
        │       ├── ft_max_d.c
        │       ├── ft_memccpy.c
        │       ├── ft_memchr.c
        │       ├── ft_memcmp.c
        │       ├── ft_memcpy.c
        │       ├── ft_memmove.c
        │       ├── ft_memset.c
        │       ├── ft_min_d.c
        │       ├── ft_pow.c
        │       ├── ft_pow_i.c
        │       ├── ft_putchar.c
        │       ├── ft_putchar_fd.c
        │       ├── ft_putendl.c
        │       ├── ft_putendl_fd.c
        │       ├── ft_puthex_downcase.c
        │       ├── ft_puthex_uppercase.c
        │       ├── ft_putnbr.c
        │       ├── ft_putnbr_base.c
        │       ├── ft_putnbr_base_i.c
        │       ├── ft_putnbr_base_li.c
        │       ├── ft_putnbr_base_ui.c
        │       ├── ft_putnbr_base_ul.c
        │       ├── ft_putnbr_fd.c
        │       ├── ft_putnbr_i.c
        │       ├── ft_putnbr_li.c
        │       ├── ft_putnbr_ui.c
        │       ├── ft_putnbr_ul.c
        │       ├── ft_putstr.c
        │       ├── ft_putstr_fd.c
        │       ├── ft_putstr_up_to.c
        │       ├── ft_salloc.c
        │       ├── ft_skip_digits.c
        │       ├── ft_skip_number.c
        │       ├── ft_split.c
        │       ├── ft_sqrt.c
        │       ├── ft_sqrt_i.c
        │       ├── ft_straddc.c
        │       ├── ft_strchr.c
        │       ├── ft_strcpy.c
        │       ├── ft_strdel.c
        │       ├── ft_strdup.c
        │       ├── ft_strjoin.c
        │       ├── ft_strjoin_and_del.c
        │       ├── ft_strjoin_and_del_del.c
        │       ├── ft_strjoin_and_free.c
        │       ├── ft_strjoin_and_free_free.c
        │       ├── ft_strlcat.c
        │       ├── ft_strlcpy.c
        │       ├── ft_strlen.c
        │       ├── ft_strmapi.c
        │       ├── ft_strnchr.c
        │       ├── ft_strncmp.c
        │       ├── ft_strnstr.c
        │       ├── ft_strrchr.c
        │       ├── ft_strtrim.c
        │       ├── ft_substr.c
        │       ├── ft_swap.c
        │       ├── ft_swap_i.c
        │       ├── ft_tolower.c
        │       ├── ft_toupper.c
        │       ├── get_next_line.c
        │       └── unless.c
        ├── main.c
        ├── parsing
        │   ├── cut_str.c
        │   ├── ft_clear_token.c
        │   ├── ft_cut_bin.c
        │   ├── ft_cut_cd.c
        │   ├── ft_cut_echo.c
        │   ├── ft_cut_env.c
        │   ├── ft_cut_exit.c
        │   ├── ft_cut_export.c
        │   ├── ft_cut_input.c
        │   ├── ft_cut_pwd.c
        │   ├── ft_cut_redirects.c
        │   ├── ft_cut_unset.c
        │   ├── ft_pre_parsing.c
        │   ├── ft_quote.c
        │   ├── history.c
        │   └── quote.c
        ├── redir
        │   ├── ft_here_doc.c
        │   ├── ft_in_file.c
        │   └── ft_pipe.c
        ├── signals.c
        ├── utils
        │   ├── ft_parse_arg.c
        │   ├── ft_str.c
        │   └── ft_write.c
        └── var
            ├── ft_var.c
            └── ft_var_sort.c
```

---

## Features

    Execution of executables from absolute, relative, or environment PATH
    Handling of arguments and options
    Support for single and double quotes similar to bash

---

## Installation

    Clone the repository: git clone <repository-url>
    Compile the project: make

---

## Usage

    Start the Minishell: ./minishell
    Enter commands and explore shell functionalities

---

## Contributors
- [kscarmy](https://github.com/kscarmy)
