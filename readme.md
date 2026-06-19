# 🛠️ MAKEFILE TỪ SỐ 0 — TỔNG HỢP KIẾN THỨC ĐẦY ĐỦ

> Tài liệu tổng hợp toàn bộ kiến thức **Makefile** từ 3 nguồn: ghi chú lý thuyết cá nhân (12 phần), slide khóa **Makefile Course** của **Nguyễn Văn Nghĩa** (50 slide), và vở viết tay 2 quyển (Makefile 1 & Makefile 2).
> Sắp xếp lại theo trình tự học từ cơ bản đến nâng cao, bổ sung giải thích chi tiết và Makefile mẫu hoàn chỉnh.

📚 Mục tiêu: hiểu **Build Process**, dùng được **GCC**, và **viết được Makefile** cho các dự án vừa, nhỏ — bao gồm cả project **Vi điều khiển (STM32)**.

⚠️ Makefile là **kỹ năng nền tảng của lập trình nhúng (Embedded)** — khi không có IDE hỗ trợ (hoặc muốn tự động hóa build), Makefile là công cụ bắt buộc phải biết.

> 🎶 *Mọi kiến thức ở đây tổng hợp từ việc tự tìm hiểu + học hỏi đồng nghiệp. Sai sót == true ? "Đóng góp" : "Khen ngợi".*

**Tài liệu tham khảo gốc:**
- 🌐 [GNU Make Manual — Rule Syntax](https://www.gnu.org/software/make/manual/make.html#Rule-Syntax)
- 🌐 [github.com/Leminuos/makefile](https://github.com/Leminuos/makefile/blob/master/Makefile)
- 🌐 [github.com/nghia12a1-t-ara/makefile](https://github.com/nghia12a1-t-ara/makefile) (source code khóa Makefile Course)
- 📺 Khóa Makefile Course — Nguyễn Văn Nghĩa ([Nhóm Lập trình điện tử](https://www.facebook.com/groups/laptrinhdientu))

---

## 📑 MỤC LỤC TỔNG QUAN

```
==================================================================
| CHƯƠNG    | NỘI DUNG                                           |
==================================================================
| MỞ ĐẦU    | Giới thiệu Makefile & Mục tiêu                     |
| CHƯƠNG 1  | BUILD PROCESS (Quá trình Build) — Cơ bản & Nhúng   |
| CHƯƠNG 2  | GCC & COMMAND LINE — Trình biên dịch               |
| CHƯƠNG 3  | MAKEFILE CƠ BẢN — Rule, Target, Build đầu tiên     |
| CHƯƠNG 4  | BIẾN, WILDCARDS & AUTOMATIC VARIABLES              |
| CHƯƠNG 5  | PHONY TARGET                                       |
| CHƯƠNG 6  | QUẢN LÝ ĐA THƯ MỤC — VPATH, foreach, wildcard      |
| CHƯƠNG 7  | MAKEFILE CHO VI ĐIỀU KHIỂN (STM32 / ARM)           |
| CHƯƠNG 8  | KIẾN THỨC NÂNG CAO — ifeq, export, include         |
| BONUS     | Makefile tổng quát hóa hoàn chỉnh + Cheat Sheet    |
==================================================================
```

### 🔖 Chi tiết các phần

<details>
<summary><b>Mở đầu & Chương 1-2: Nền tảng</b></summary>

- [Makefile là gì & tại sao cần?](#makefile-là-gì--tại-sao-cần)
- [1.1. Build Process cơ bản (4 bước)](#11-build-process-cơ-bản-4-bước)
- [1.2. Build Process cho hệ thống nhúng (Embedded)](#12-build-process-cho-hệ-thống-nhúng-embedded)
- [1.3. Trình biên dịch (Compiler) là gì?](#13-trình-biên-dịch-compiler-là-gì)
- [1.4. GCC là gì?](#14-gcc-là-gì)
- [2.1. Cài đặt môi trường (MingW / Cygwin / MSYS2)](#21-cài-đặt-môi-trường-mingw--cygwin--msys2)
- [2.2. Command Line cơ bản](#22-command-line-cơ-bản)
- [2.3. Build thủ công 4 bước bằng GCC](#23-build-thủ-công-4-bước-bằng-gcc)
- [2.4. Build dự án bằng GCC (1 file & nhiều file)](#24-build-dự-án-bằng-gcc-1-file--nhiều-file)
</details>

<details>
<summary><b>Chương 3-4: Makefile cơ bản</b></summary>

- [3.1. Tại sao cần Makefile?](#31-tại-sao-cần-makefile)
- [3.2. Makefile là gì?](#32-makefile-là-gì)
- [3.3. Từ lệnh GCC đến Makefile](#33-từ-lệnh-gcc-đến-makefile)
- [3.4. Rule cơ bản của Makefile](#34-rule-cơ-bản-của-makefile)
- [3.5. Makefile đầu tiên](#35-makefile-đầu-tiên)
- [4.1. Biến (Variables) trong Makefile](#41-biến-variables-trong-makefile)
- [4.2. In giá trị biến (Debug)](#42-in-giá-trị-biến-debug)
- [4.3. Automatic Variables](#43-automatic-variables)
- [4.4. Wildcards](#44-wildcards)
- [4.5. Pattern Rules](#45-pattern-rules)
</details>

<details>
<summary><b>Chương 5-6: Tổ chức dự án</b></summary>

- [5.1. Vấn đề trùng tên file](#51-vấn-đề-trùng-tên-file)
- [5.2. .PHONY](#52-phony)
- [5.3. Các PHONY target chuẩn](#53-các-phony-target-chuẩn)
- [6.1. VPATH & CFLAGS](#61-vpath--cflags)
- [6.2. vpath directive](#62-vpath-directive)
- [6.3. Hàm foreach](#63-hàm-foreach)
- [6.4. Hàm wildcard](#64-hàm-wildcard)
- [6.5. Hàm notdir](#65-hàm-notdir)
</details>

<details>
<summary><b>Chương 7-8 & Bonus: Nhúng & Nâng cao</b></summary>

- [7.1. Bài toán Vi điều khiển](#71-bài-toán-vi-điều-khiển)
- [7.2. Build Process nhúng cho bài toán](#72-build-process-nhúng-cho-bài-toán)
- [7.3. Compiler Options & Linker Options](#73-compiler-options--linker-options)
- [7.4. Objcopy & Nạp code (ST-LINK)](#74-objcopy--nạp-code-st-link)
- [8.1. ifeq, export & $(error)](#81-ifeq-export--error)
- [8.2. include Makefile](#82-include-makefile)
- [8.3. -D define](#83--d-define)
- [BONUS: Makefile tổng quát hóa hoàn chỉnh](#-bonus-makefile-tổng-quát-hóa-hoàn-chỉnh)
- [BONUS: Cheat Sheet](#-bonus-cheat-sheet)
</details>

---

# 📖 MỞ ĐẦU

## Makefile là gì & tại sao cần?

> **Bản chất của Makefile**: là một file **kịch bản (script)** dùng để **thực thi các câu lệnh (command)** — chủ yếu là các lệnh biên dịch (compile).

Khi dùng Makefile để **rebuild** một dự án, nó chỉ **build lại những file đã thay đổi**, giúp **giảm đáng kể thời gian rebuild** so với việc build lại toàn bộ.

**Tại sao quan trọng với lập trình nhúng?**

| Lý do | Giải thích |
|-------|------------|
| **Không phụ thuộc IDE** | Nhiều dòng chip mới không có IDE hỗ trợ → phải dùng Makefile để build ra file `.bin` / `.hex` |
| **Tự động hóa** | Gộp toàn bộ chuỗi lệnh GCC vào 1 file, chạy 1 lệnh `make` thay vì gõ hàng chục lệnh |
| **Build thông minh** | Chỉ biên dịch lại file thay đổi, tiết kiệm thời gian với dự án lớn |

> 🎯 **Mục tiêu khóa học:**
> - Nắm được **Build Process** cơ bản trong hệ thống nhúng
> - Biết sử dụng **Compiler GCC**
> - Nắm các khái niệm cơ bản về **Makefile**
> - Viết được **Makefile cho project Vi điều khiển**
> - **Tổng quát hóa** Makefile cho các project khác nhau

---

# CHƯƠNG 1: BUILD PROCESS (QUÁ TRÌNH BUILD)

> Từ Source Code đến file nhị phân nạp vào Target (chip). Đây là phần lý thuyết nền tảng quan trọng nhất.

## 1.1. Build Process cơ bản (4 bước)

Quá trình biến mã nguồn thành file chạy gồm **4 giai đoạn** nối tiếp:

```
   Source files (.c / .cpp / .h)
              │
              ▼
   ┌──────────────────┐
   │   PREPROCESSOR   │  Tiền xử lý
   └──────────────────┘
              │   → Include Header / Expand Macro (.i / .ii)
              ▼
   ┌──────────────────┐
   │   COMPILATION    │  Trình biên dịch
   └──────────────────┘
              │   → Assembly Code (.s)
              ▼
   ┌──────────────────┐
   │     ASSEMBLE     │  ◄── Source files (.s)
   └──────────────────┘
              │   → Object File (.o)
              ▼
   ┌──────────────────┐
   │     LINKING      │  ◄── Static Library (.lib / .a)
   └──────────────────┘
              │
              ▼
     Executable file (.exe)
```

| Giai đoạn | Đầu vào → Đầu ra | Nhiệm vụ |
|-----------|------------------|----------|
| **Preprocessor** (Tiền xử lý) | `.c/.cpp/.h` → `.i/.ii` | Thay thế **Macro** bằng định nghĩa tương ứng; **chèn nội dung `.h` vào `.c`** thành file `.i` |
| **Compilation** (Biên dịch) | `.i` → `.s` | Trình biên dịch dịch file `.i` thành **mã Assembly** (.s) |
| **Assemble** (Hợp dịch) | `.s` → `.o` | "Lắp ghép" mã assembly thành **Object File** — mã nhị phân **nhưng còn thiếu** (chưa đủ địa chỉ) |
| **Linking** (Liên kết) | `.o` + `.a` → `.exe` | Liên kết các object file + thư viện tĩnh thành file chạy hoàn chỉnh |

## 1.2. Build Process cho hệ thống nhúng (Embedded)

Với hệ thống nhúng, quy trình chi tiết hơn ở khâu **Compilation** và bổ sung khâu **Locator**:

```
   .c / .cpp / .h
        │
   [Preprocessor] ──► .i (Extended files)
        │
   [Compilation] ── parser ──► Code generator ──► .s (Assembly Source files)
        │
   [Assembler] ──► .o (Object files)
        │            = mã máy đặc thù kiến trúc, KHÔNG có địa chỉ tuyệt đối
        │              (relocatable file — file có thể tái định vị)
        ▼
```

Sau đó qua giai đoạn **Linking → Locating**:

```
   .o (Re-locatable object files)
   .a (Static Libraries)
        │
        ▼
   [Linker] ──► [Locator] ◄── .ld (Linker script)
        │
        ▼
   .elf (Executable & debug file)
        │
   [Objcopy tool]
        │
        ▼
   .ihex (Intel hex format)   /   .bin (Bin format)
```

> 💡 **Giải thích các thành phần nhúng:**
> - **Object file (.o)**: mã máy đặc thù kiến trúc bộ xử lý, **không có địa chỉ tuyệt đối** (relocatable).
> - **Locator**: **ánh xạ vùng nhớ** của file `.o` (đang ở địa chỉ máy tính) **xuống vùng nhớ của vi điều khiển**. Vì build trên máy tính nên ban đầu là địa chỉ máy tính → cần file để ánh xạ.
> - **Linker Script (.ld)**: file chỉ định cách bố trí bộ nhớ cho Locator.
> - **.elf**: file thực thi, **hỗ trợ debug**.
> - **.ihex / .bin**: file **nạp xuống vi điều khiển** để thực thi code.

> 📌 **Đọc thêm** (blog laptrinhcnhung.blogspot.com): Preprocessor, Build Process, **Cross Compiler**, quá trình Linking, Static Library vs Shared Library, Linker Script File.

## 1.3. Trình biên dịch (Compiler) là gì?

> *"Compiler (trình biên dịch) là một chương trình máy tính làm công việc dịch các chuỗi câu lệnh viết bằng ngôn ngữ lập trình thành chương trình tương đương nhưng viết dưới dạng ngôn ngữ máy tính. Chương trình mới này được gọi là mã đối tượng (object code)."*

**Vai trò của Compiler** (`.asm / .c / .cpp + .h` → `.o / listing`):
- Tạo mã **ROM-able** (nạp được vào ROM)
- Tạo mã **được tối ưu** (Optimized)
- Tạo mã **Re-entrant** (tái nhập)
- Hỗ trợ nhiều dòng vi điều khiển trong 1 họ
- Hỗ trợ nhiều mô hình bộ nhớ (Memory Models)

## 1.4. GCC là gì?

> **GCC — GNU Compiler Collection** — là **tập hợp các trình biên dịch** được thiết kế cho nhiều ngôn ngữ lập trình khác nhau. Đây là **thành phần quan trọng của GNU toolchain**.

GCC đảm nhận các khâu **Compilation → Assemble** trong build process (từ `.i/.ii` qua `.s` đến `.o`).

---

# CHƯƠNG 2: GCC & COMMAND LINE

## 2.1. Cài đặt môi trường (MingW / Cygwin / MSYS2)

GCC có sẵn khi cài một số môi trường:

| Công cụ | Mô tả |
|---------|-------|
| **CodeBlocks / Dev C++** | Đã tích hợp sẵn GCC |
| **MingW** | Minimalist GNU for Windows |
| **Cygwin** | Môi trường giống Unix trên Windows (lưu ý cài package **GCC** và **make**) |
| **MSYS2** | Tập hợp tool + library để dễ build/install/run **native Windows software** (GCC, mingw-w64, CPython, CMake, Meson, OpenSSL, FFmpeg, Rust, Ruby...) |

> 💡 **Khái niệm IDE**: `IDE = UI (Giao diện) + Env (Môi trường)`. VSCode, Notepad chỉ là **UI** — ta dùng MSYS2/MingW làm **môi trường (Env)** để build.

> ⚙️ **Tự config môi trường (Windows)**: Edit Environment System → thêm `PATH`:
> - `C:\msys64\usr\bin`
> - `C:\msys64\ucrt64\...`
> Sau đó kiểm tra: `gcc --version` và `make --version`.

```bash
$ gcc --version
gcc (GCC) 10.2.0
Copyright (C) 2020 Free Software Foundation, Inc.

$ make --version
GNU Make 3.81
```

## 2.2. Command Line cơ bản

Các lệnh thao tác file/folder hay dùng:

```bash
gcc --version            # Kiểm tra phiên bản GCC
mkdir <folder_name>      # Tạo folder mới
cd <folder_son>          # Di chuyển vào folder con
touch <file_names>       # Tạo một file mới
cls                      # Xóa màn hình CMD (clear)
```

> 💡 Tìm hiểu thêm tại **ss64.com** — trang tổng hợp rất nhiều command CMD/PowerShell.

## 2.3. Build thủ công 4 bước bằng GCC

Có thể chạy **từng giai đoạn** của Build Process bằng các flag GCC tương ứng:

```bash
gcc -E main.c -o main.i      # 1. Preprocessor:  .c → .i
gcc -S main.i -o main.s      # 2. Compilation:   .i → .s
as  main.s -o main.o         # 3. Assemble:      .s → .o
gcc -v -o main main.o        # 4. Linking:       .o → file chạy
```

| Flag | Ý nghĩa |
|------|---------|
| `-E` | Chỉ chạy tới bước Preprocessor |
| `-S` | Chỉ chạy tới bước Compilation (tạo assembly) |
| `as` | Lệnh Assembler (tạo object) |
| `-v` | Verbose (in chi tiết quá trình) |

> 💡 Ở bước Preprocessor: GCC **add thư viện vào** `main.c` → `main.i`, đồng thời **xóa các `#define`** và **thay thế bằng giá trị tương ứng**.

## 2.4. Build dự án bằng GCC (1 file & nhiều file)

### 1. Trường hợp 1 file `main.c` duy nhất

```c
#include <stdio.h>
int main() {
    printf("Hello world");
    return 0;
}
```

Build bằng GCC (PowerShell):

```bash
gcc main.c -o main.exe
.\main.exe
```

| Thành phần | Ý nghĩa |
|-----------|---------|
| `main.c` | File cần biên dịch (input) |
| `-o` | Output |
| `main.exe` | File output (file chạy của chương trình) |

### 2. Trường hợp nhiều file `.c`, `.h` liên kết với nhau

Giả sử có cấu trúc: `main.c`, `lib.c`, `lib.h`.

**Cách 1 — Build từng file `.o` rồi link:**

```bash
gcc -c main.c -o main.o          # Build ra main.o
gcc -c lib.c  -o lib.o           # Build ra lib.o
gcc main.o lib.o -o main.exe     # Link các .o → file chạy main.exe
```

| Flag | Ý nghĩa |
|------|---------|
| `-c` | Tạo ra **file object** (.o) |
| `-o` | Tạo ra **file output** |

**Cách 2 — Gộp lệnh, dùng `-I.`:**

```bash
gcc main.c lib.c -o main.exe -I.   # Build thẳng ra main.exe
```

> 💡 `-I.` báo cho GCC **tìm trong thư mục hiện tại (`.`)** để thêm các file header (`.h`).
> ⚠️ Nếu file `.h` nằm trong thư mục `inc` (không phải thư mục hiện tại) → sẽ **báo lỗi** vì không tìm thấy header.

> ❌ **Nhận xét**: Cả 2 cách trên đều **không "clean"** (gọn gàng) với các dự án lớn — phải gõ rất nhiều lệnh và khi sửa 1 file lại phải build lại tất cả.
> ✅ **→ Makefile chính là để dùng cho trường hợp này!**

---

# CHƯƠNG 3: MAKEFILE CƠ BẢN

## 3.1. Tại sao cần Makefile?

Hình dung tình huống thực tế:

```
┌─────────────────────────────────────────────────────────┐
│ Dự án có nhiều source files (GPIO.h, GPIO.c, main.c,     │
│ stm32_startup.c, syscalls.c...) build bằng IDE (Keil C)  │
├─────────────────────────────────────────────────────────┤
│ Một lúc nào đó, bạn muốn sửa hoặc thêm 1 file (led.c)    │
├─────────────────────────────────────────────────────────┤
│ IDE: Add file vào project & REBUILD ALL FILE             │
│   → Tốn rất nhiều thời gian với dự án lớn ❌             │
├─────────────────────────────────────────────────────────┤
│ Makefile: chỉ cần BUILD file sửa/thêm (led.c) ✅        │
└─────────────────────────────────────────────────────────┘
```

> 💡 Nếu dùng CMD gõ lệnh `gcc` thủ công thì **rất mất thời gian**, và khi thêm file mới phải **rebuild lại tất cả** → mệt. Makefile giải quyết cả hai vấn đề.

## 3.2. Makefile là gì?

> **Makefile** là một file **script** chứa các thông tin:
> - **Project structure** (cấu trúc dự án): các file và **dependencies** (phụ thuộc) giữa chúng
> - **Commands** để tạo file (object file, elf/bin/hex file...)

Lệnh **`make`** sẽ **đọc nội dung Makefile**, **hiểu cấu trúc** dự án, và **thực thi các command**.

**Công cụ chạy Makefile**: Cygwin / MingW / **GNU Make**.

## 3.3. Từ lệnh GCC đến Makefile

Ý tưởng cốt lõi: **gộp các lệnh GCC vào một file script duy nhất**.

Dự án: `main.c → main.o → main.exe`

**Với GCC (gõ tay từng lệnh):**
```bash
gcc -c main.c -o main.o      # Generate object file
gcc main.o -o main.exe       # Generate .exe file
main.exe                     # Run .exe file → "Hello"
```

**Với Makefile (gộp vào 1 file):**
```makefile
main.o: main.c
	gcc -c main.c -o main.o

build: main.o
	gcc main.o -o abc.exe

run:
	abc.exe
```

> 💡 Toàn bộ chuỗi lệnh GCC giờ nằm gọn trong 1 file — gọi `make build`, `make run` thay vì gõ lại từng lệnh.

## 3.4. Rule cơ bản của Makefile

Đây là **cú pháp xương sống** của mọi Makefile:

```
target … : prerequisites …
<TAB>recipe
       …
```

```
   ┌──────────┐        ┌─────────────────────────┐
   │  target  │  :     │  prerequisites          │
   └──────────┘        └─────────────────────────┘
   (File/nhiệm vụ      (Input files để tạo target)
    muốn make tạo ra)
        │
   <TAB>│  recipe   ◄── Action (câu lệnh) mà make thực thi
        │  …
```

| Thành phần | Vai trò |
|-----------|---------|
| **Target** | Tên của **nhiệm vụ** hoặc **file** mà bạn muốn `make` tạo ra |
| **Prerequisites / Dependency** | Các **file cần thiết** để tạo ra target (input) |
| **Recipe / Action** | **Câu lệnh compile** để tạo Target từ Dependency |
| **Rule** | Toàn bộ khối trên — các quy tắc cần thực hiện khi compile |

> ⚠️ **CỰC KỲ QUAN TRỌNG — Lỗi kinh điển của người mới**: Recipe (Action) **phải thụt lùi vào bằng 1 phím `TAB`** (không phải dấu cách / spaces) so với Target. Sai chỗ này → Makefile báo lỗi ngay.

**Ví dụ minh họa đầy đủ** (có phân chia thư mục Source/Object):

```makefile
main.o: Source/main.c
	gcc -c Source/main.c -o Object/main.o

build: Object/main.o
	gcc Object/main.o -o Object/main.exe

run:
	@Object/main.exe

clean:
	rm Object/*
```

> 💡 Ký tự `@` trước lệnh → **không in dòng lệnh đó ra màn hình** khi chạy (chỉ chạy ngầm).

## 3.5. Makefile đầu tiên

Một Makefile cơ bản nhất:

```makefile
CC=gcc
CFLAGS=-I.

main: main.c lib.c
	$(CC) main.c lib.c -o main.exe -I.
```

Sau khi chạy lệnh:
```bash
make main
.\main.exe
```
→ tạo ra `main.exe` là file chạy của chương trình.

> 💡 `make main` = build target tên `main`. Nếu chỉ gõ `make` thì nó chạy **target đầu tiên** trong file.

---

# CHƯƠNG 4: BIẾN, WILDCARDS & AUTOMATIC VARIABLES

## 4.1. Biến (Variables) trong Makefile

Biến giúp **tổng quát hóa** Makefile, **tránh viết cứng** (hardcode) tên file cụ thể.

**Khởi tạo:**
```makefile
NAME = VALUE
```

**Gọi (call) biến:**
```makefile
$(NAME)    hoặc    ${NAME}
```

**Các toán tử gán:**

| Toán tử | Ý nghĩa |
|---------|---------|
| `=` | Gán giá trị (gán đệ quy — recursive) |
| `:=` | Gán **1 giá trị** (gán tức thời — simple/immediate) |
| `+=` | **Thêm** giá trị (nối thêm vào biến) |

**Ví dụ:**
```makefile
PRO_DIR    :=
PROJ_NAME  := ADCXYZ
OUTPUT_PATH := $(PRO_DIR)/output
```

```makefile
CC = gcc

lib.o: lib.c
	$(CC) -c lib.c -o lib.o -I.
```

> 💡 Symbol để truy cập giá trị biến: `$(variable_name)`. Ví dụ `PROJ_NAME := ADCXYZ` → `$(PROJ_NAME)` cho ra `ADCXYZ`.

## 4.2. In giá trị biến (Debug)

Khi làm việc với Makefile, cần in giá trị biến ra để **kiểm tra / debug** → dùng lệnh `echo` kết hợp **string substitution**:

```makefile
print-%:
	@echo $($(subst print-,,$@))
```

Chạy:
```bash
$ make print-PROJ_NAME
ADCXYZ
```

> 💡 **Giải thích cơ chế**: `make print-PROJ_NAME` → `$@` = `print-PROJ_NAME` → `subst print-,,$@` xóa chuỗi `print-` → còn `PROJ_NAME` → `$(PROJ_NAME)` in ra giá trị.
> - `@` → không in dòng lệnh ra
> - `@echo "..."` → in nội dung ra màn hình

## 4.3. Automatic Variables

> Là các **biến tự động** make tạo sẵn để **tổng quát hóa rule** — không cần viết tên file cụ thể.

**Bảng đầy đủ:**

| Symbol | Ý nghĩa |
|--------|---------|
| `$@` | Tên file của **target** (thành phần bên trái dấu `:`) |
| `$%` | Phần tử tên file của đặc tả thành viên lưu trữ (archive member) |
| `$<` | Tên của **prerequisite đầu tiên** (đầu tiên trong danh sách dependency) |
| `$?` | Tên tất cả prerequisite **mới hơn target**, ngăn cách bởi dấu cách |
| `$^` | Tên **tất cả** prerequisite, ngăn cách bởi dấu cách |
| `$+` | Giống `$^` nhưng **bao gồm cả bản sao trùng lặp** (duplicates) |
| `$*` | Phần **gốc (stem)** của tên file target (tên file không có hậu tố) |

**Ví dụ tổng quát hóa:**

```makefile
# Trước (viết cứng):
main.o: source/main.c
	gcc -c source/main.c -o output/main.o

# Sau (dùng automatic variables):
main.o: source/main.c
	gcc -c $^ -o output/$@
```

## 4.4. Wildcards

> **Wildcards** (ký tự đại diện) = đại diện cho **một đối tượng có phần mở rộng** bất kỳ.

| Ký tự | Ý nghĩa |
|-------|---------|
| `%.o` | Pattern của một tệp đối tượng có phần mở rộng `.o` |
| `%.c` | Pattern của một tệp đối tượng có phần mở rộng `.c` |
| `*` | Đại diện nhiều ký tự — `*.c` = danh sách tất cả file kết thúc bằng `.c` |
| `?` | Đại diện 1 ký tự |
| `[…]` | Đại diện 1 ký tự trong tập hợp |

**Hàm `wildcard`** — lấy danh sách file thực tế trong thư mục:

```makefile
SRC_DIRS  = C:/Users/Admin/OneDrive/Desktop/FPT/
SRC_FILES := $(wildcard $(SRC_DIRS)/*)
```
→ `SRC_FILES` chứa **tất cả file trong PATH** đó.

```makefile
clean:
	@rm output/*       # Xóa tất cả file trong folder 'output'
```

> ⚠️ Lưu ý về `wildcard`: nếu có nhiều đường dẫn, `$(wildcard $(DIRS)/*)` **chỉ lấy file của đường dẫn cuối cùng** → để lấy hết file ở **nhiều thư mục** phải kết hợp với `foreach` (xem [Chương 6](#63-hàm-foreach)).

## 4.5. Pattern Rules

> Quy tắc theo khuôn mẫu — chỉ cho make biết **cách tạo 1 file `.o` từ 1 file `.c` tương ứng** (bất kỳ).

```makefile
%.o : %.c
	recipe…
```

**Ví dụ hoàn chỉnh** (kết hợp biến + automatic variable + pattern rule):

```makefile
CC = gcc
CFLAGS = -I.
DEPS = lib.h

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

main: main.o lib.o
	gcc main.o lib.o -o main.exe
```

> 💡 Dòng `%.o: %.c $(DEPS)` nghĩa là: **mọi** file `.o` đều được tạo từ file `.c` cùng tên (và phụ thuộc `lib.h`). `$@` = file .o đích, `$<` = file .c nguồn.

---

# CHƯƠNG 5: PHONY TARGET

## 5.1. Vấn đề trùng tên file

> **Target** vừa có thể là **tên file muốn tạo**, vừa có thể là **tên một "hàm" (nhiệm vụ)**.

Vấn đề xảy ra khi trong project có một **file trùng tên với target**. Ví dụ có target:

```makefile
clean:
	rm -f *.o *.exe
```

Nếu trong thư mục **có sẵn 1 file tên `clean`**, khi chạy `make clean`:

```bash
make: 'clean' is up to date.
```

→ `make` tưởng `clean` là file đã tồn tại và "up to date" nên **KHÔNG thực hiện** lệnh trong target!

## 5.2. .PHONY

Để báo cho make biết `clean` là một **action (nhiệm vụ)** chứ không phải file → dùng `.PHONY`:

```makefile
.PHONY: clean
clean:
	rm -f *.exe *.o
```

> 💡 `.PHONY` "đánh dấu" target là **giả** (không phải file thật) → make luôn thực thi recipe của nó, bất kể có file trùng tên hay không. Cũng dùng để **phân biệt** `make build` (chạy action) với một file tên `build`.

## 5.3. Các PHONY target chuẩn

Một số target PHONY hay dùng theo quy ước (GNU):

| Target | Chức năng |
|--------|-----------|
| `all` | Thực hiện build **toàn bộ** |
| `install` | Tạo bản cài đặt của ứng dụng từ việc compile binary |
| `clean` | Xóa các **binary file** được tạo từ source |
| `distclean` | Xóa **tất cả** file được tạo ra mà **không** nằm trong source chính |
| `TAGS` | Tạo bảng tag để editor dùng |
| `info` | Tạo GNU info file từ textinfo source |
| `check` | Chạy bất kỳ **test** nào tương ứng với chương trình |

> 💡 Vì Makefile là viết cho **người khác cùng dùng** → nên dùng các tên chuẩn này để **tránh nhầm lẫn**.

---

# CHƯƠNG 6: QUẢN LÝ ĐA THƯ MỤC

> Từ trước tới giờ ta để các file `.c`, `.h` ở thư mục gốc (root) nên thao tác đơn giản. Thực tế dự án có **nhiều thư mục** — đây là lúc cần VPATH, foreach, wildcard, notdir.

## 6.1. VPATH & CFLAGS

Tình huống: file `.c` để trong folder `src`, file `.h` để trong folder `inc`.

**Giải pháp:**
```makefile
CFLAGS = -I inc      # báo nơi tìm file .h (header)
VPATH  = src         # báo nơi tìm file .c (source)
```

> 💡 **Cơ chế hoạt động**: make sẽ **chủ động tìm trong thư mục gốc (`.`) trước**, nếu không có các file `.c`/`.h` cần tìm thì nó **tìm tiếp trong các folder bạn định nghĩa** ở trên. Nhờ vậy không xảy ra lỗi thiếu file — đây là **sức mạnh của CFLAGS và VPATH**.

## 6.2. vpath directive

> **VPATH** chỉ định danh sách thư mục mà make **tìm kiếm prerequisites và targets**. Tự động tìm tất cả thư mục để lấy file.

Cách dùng `vpath` (chữ thường) theo từng loại file:

```makefile
# search path .c and .h files
vpath %.c $(SRC_DIRS)
vpath %.h $(INC_DIRS)
```

> 💡 Khác biệt: `VPATH` (hoa) áp dụng cho **mọi loại file**; `vpath %.c <dir>` (thường) chỉ định **riêng cho từng pattern** → kiểm soát chính xác hơn.

## 6.3. Hàm foreach

> Câu hỏi: nếu có **nhiều folder** chứa file `.c` hoặc nhiều folder chứa file `.h` thì làm sao? → Dùng `foreach`.

**Cú pháp:**
```makefile
$(foreach var, list, text)
```

| Tham số | Ý nghĩa |
|---------|---------|
| `var` | Biến tạm lưu mỗi phần tử trong `list` ở mỗi vòng lặp |
| `list` | Danh sách các phần tử muốn lặp qua |
| `text` | Phần tử / biểu thức thực hiện với mỗi phần tử trong `list` |

**Ví dụ — tạo CFLAGS và VPATH cho nhiều thư mục:**

```makefile
INC_DIR := ./inc ./core ./a ./b      # Thêm folder vào đây khi cần
SRC_DIR := ./src ./core

CFLAGS = $(foreach INC_DIR, $(INC_DIR), -I$(INC_DIR))
VPATH  = $(foreach SRC_DIR, $(SRC_DIR), $(SRC_DIR))
```

**Ví dụ — lấy tất cả file trong nhiều folder (kết hợp wildcard):**

```makefile
dirs  := a b c d
files := $(foreach dir, $(dirs), $(wildcard $(dir)/*))
```
→ Lấy tất cả file trong tất cả folder của `dirs`.

## 6.4. Hàm wildcard

> Hàm này khiến một đoạn text được **dùng lặp lại**, mỗi lần với một phép thay thế khác nhau. `wildcard` **lấy ra danh sách file** thực tế.

(Đã trình bày chi tiết ở [mục 4.4](#44-wildcards) — nhắc lại: nếu nhiều đường dẫn, `wildcard` chỉ lấy file của đường dẫn cuối → kết hợp `foreach` để lấy hết.)

## 6.5. Hàm notdir

> **`notdir`** (not direct) — dùng để lấy **tên file/folder bỏ đi phần đường dẫn (path)**, giữ lại tên source thuần.

```makefile
OJB_FILES := $(notdir $(SRC_FILES))
```

```bash
$ make print-OJB_FILES
main.c sub.c sum.c
```

> 💡 Nếu `SRC_FILES` là `source/main.c source/sub.c ...` thì `notdir` cho ra `main.c sub.c ...` (bỏ `source/`).

**Make Process tổng thể** (luồng biến đổi file):

```
   GPIO.c   main.c   startup.c
        │       │        │
        ▼       ▼        ▼
   GPIO.o   main.o   startup.o
        └───────┼────────┘
                ▼
            GPIO.elf
                ▼
            GPIO.hex
```

---

# CHƯƠNG 7: MAKEFILE CHO VI ĐIỀU KHIỂN (STM32 / ARM)

> Phần ứng dụng thực tế: viết Makefile build chương trình **Blink LED GPIO** cho chip **STM32F401 (NUCLEO Board)**.

## 7.1. Bài toán Vi điều khiển

**Yêu cầu:**
- Chương trình: **Blink LED GPIO**
- Source code: `GPIO.c`, `GPIO.h`, `main.c`
- **Startup File** + **Linker File** (.ld) — được cung cấp sẵn
- Phần mềm nạp code: **STM32 ST-LINK Utility**
- Phần cứng: STM32F401 NUCLEO Board

**Cài đặt phần mềm cần thiết:**

| Công cụ | Mục đích |
|---------|----------|
| **GNU ARM Toolchain** (GCC for ARM) | Compiler GCC cho chip ARM |
| **STM32 ST-LINK Utility** (STSW-LINK004) | Phần mềm nạp code |
| GNU Make | Chạy Makefile |

## 7.2. Build Process nhúng cho bài toán

Áp dụng Build Process Embedded ([Chương 1.2](#12-build-process-cho-hệ-thống-nhúng-embedded)) vào bài toán cụ thể:

```
   main.c   GPIO.h   GPIO.c
        │
   [Preprocessor]
        ▼
   main.i   GPIO.i
        │
   [Compilation]
        ▼
   main.s   GPIO.s   startup.s
        │
   [Assemble]
        ▼
   main.o   GPIO.o   startup.o
        │
   [Linker + Locator] ◄── stm_ld.ld
        ▼
   GPIO.elf
        │
   [Objcopy tool]
        ▼
   GPIO.hex   GPIO.bin
```

**Cấu trúc lệnh tổng quát:**
```
<Compiler Options> -o <Target> <All Prerequisite>     # Compile
<Linker Options>   -o <Target> <All Prerequisite>     # Link → file .elf
```

## 7.3. Compiler Options & Linker Options

**Compiler Options** (dùng `arm-none-eabi-gcc`):

| Option | Ý nghĩa |
|--------|---------|
| `-mcpu=cortex-m4` | Chỉ định lõi CPU (Cortex-M4 cho STM32F401) |
| `-mthumb` | Dùng tập lệnh Thumb |
| `-std=gnu11` | Chuẩn ngôn ngữ C (GNU C11) |
| `-Ox` | Mức tối ưu (`-O0`, `-O1`, `-O2`...) |
| `-I$(Include_DIR)` | Đường dẫn tìm header |

**Linker Options** (dùng `arm-none-eabi-ld`):

| Option | Ý nghĩa |
|--------|---------|
| `-T $(LINKER_FILE)` | Chỉ định **linker script** (.ld) |
| `-Map <path.map>` hoặc `-Wl,-Map=<path.map>` | Xuất file **.map** (bản đồ bộ nhớ) |
| `-nostdlib` | **Không** dùng thư viện chuẩn (standard library) |

> 💡 **File `.map`**: bản đồ bộ nhớ — cho biết **hàm/biến được đặt ở địa chỉ nào**. Rất hữu ích khi debug bố trí bộ nhớ.
> 💡 **`-nostdlib`**: dùng thư viện chuẩn khác (tự cung cấp), không lấy thư viện chuẩn mặc định.
> 📌 Tra thêm: "compiler option arm gcc" để biết đầy đủ các flag.

## 7.4. Objcopy & Nạp code (ST-LINK)

**Tạo file hex từ elf** (Objcopy):
```bash
objcopy.exe -O ihex <file.elf> <file.hex>
```

**Nạp code bằng ST-LINK CLI** (Utility — giao tiếp CLI):
```bash
ST-LINK_CLI.exe -ME                                  # Mass Erase: xóa toàn bộ chip
ST-LINK_CLI.exe -SE <section>                        # Section Erase: xóa từng section
ST-LINK_CLI.exe -p <file.hex> <địa chỉ bắt đầu nạp>  # Program: nạp file hex
ST-LINK_CLI.exe -rst                                 # Reset vi điều khiển (sau khi nạp)
```

| Flag | Ý nghĩa |
|------|---------|
| `-ME` | Mass Erase — xóa toàn bộ chip |
| `-SE` | Section Erase — xóa từng section |
| `-p <file.hex> <addr>` | Nạp code vào địa chỉ chỉ định (vd `0x08000000`) |
| `-rst` | Reset vi điều khiển sau khi nạp |

> 💡 **Địa chỉ `0x08000000`** thường là điểm bắt đầu Flash của STM32 (sau vùng bootloader). → Kết quả: LED nhấp nháy 🟢.

---

# CHƯƠNG 8: KIẾN THỨC NÂNG CAO

## 8.1. ifeq, export & $(error)

> **Vấn đề**: dùng **nhiều module** trong một test program → chẳng lẽ phải **sửa Makefile cho mỗi module**? → **KHÔNG**. Dùng `export` + `ifeq`.

**Cơ chế**: truyền tên module qua biến môi trường `MODULE`, Makefile đọc và build module tương ứng.

```makefile
# Warning with empty module
ifeq ($(MODULE),)
    $(error export MODULE before starting tests)
endif

PRO_DIR     := .
PATH_OUTPUT  = ./output
PROJ_NAME   := $(MODULE)
INC_DIRS     = D:/FPT/GAM_DAP_Traning/Makefile/Examples/Endian_Test/driver/$(MODULE)/include
```

Cách dùng trên terminal:
```bash
$ export MODULE=gpio        # set biến môi trường (Windows: set MODULE=gpio)
$ make clear; make build
```

| Cú pháp | Ý nghĩa |
|---------|---------|
| `ifeq (A,B) … endif` | Kiểm tra điều kiện — ở đây kiểm tra `MODULE` có rỗng không |
| `$(error msg)` | Dừng make và in lỗi (báo phải export MODULE trước khi test) |
| `export MODULE=gpio` | Đặt biến môi trường để Makefile dùng |

> 💡 Có thể kiểm tra giá trị đã set: `make print-MODULE`.

## 8.2. include Makefile

> Cho phép **chèn (include) một Makefile khác** hoặc file config của Makefile vào Makefile hiện tại.

```makefile
include <dir/file>
```

Các loại file có thể include:
- `File make`
- `File .mak`
- `File .mk`

```
   File .mk / .mak / make  ──  include <dir/file>  ──►  Makefile
```

> 💡 Giúp **tách cấu hình** (biến, đường dẫn, rule chung) ra file riêng → Makefile chính gọn gàng, tái sử dụng được giữa nhiều project.

## 8.3. -D define

> Flag `-D` cho phép **định nghĩa macro** ngay từ command line (như `#define` trong code).

```bash
gcc -DDEBUG main.c -o main.exe        # tương đương #define DEBUG
```

> 💡 Hữu ích để bật/tắt các khối code điều kiện (`#ifdef DEBUG …`) mà không cần sửa source — chỉ đổi flag build.

---

# 🎁 BONUS: MAKEFILE TỔNG QUÁT HÓA HOÀN CHỈNH

> Gom tất cả kiến thức trên thành 1 Makefile **tổng quát hóa** — chỉ cần khai báo thư mục, không cần sửa khi thêm file.

```makefile
CC = gcc

# Khai báo các thư mục source và include
INC_DIR := ./inc ./core
SRC_DIR := ./src ./core

# Tự sinh CFLAGS (-I cho từng inc dir) và VPATH (cho từng src dir)
CFLAGS = $(foreach INC_DIR, $(INC_DIR), -I$(INC_DIR))
VPATH  = $(foreach SRC_DIR, $(SRC_DIR), $(SRC_DIR))

# Pattern rule: mọi .o build từ .c cùng tên
%.o: %.c
	$(CC) -c $(CFLAGS) $< -o $@

# Build toàn bộ
all: main.o lib.o core.o
	gcc main.o lib.o core.o -o main.exe

# Dọn dẹp
clean:
	rm -f *.o *.exe

.PHONY: clean all
```

> 💡 **Sức mạnh**: khi thêm thư mục source/include mới, chỉ cần **thêm vào `INC_DIR` / `SRC_DIR`** — phần còn lại (`foreach`, pattern rule) **tự xử lý**.

---

# 📋 BONUS: CHEAT SHEET

### Build Process (4 bước + nhúng)

```
.c/.h ─[Preprocessor]→ .i ─[Compilation]→ .s ─[Assemble]→ .o ─[Linking]→ .exe
Nhúng:  ... .o ─[Linker+Locator (.ld)]→ .elf ─[Objcopy]→ .hex / .bin
```

### Lệnh GCC theo từng bước

```bash
gcc -E main.c -o main.i      # Preprocess
gcc -S main.i -o main.s      # Compile
as  main.s   -o main.o       # Assemble
gcc main.o   -o main.exe     # Link
gcc -c main.c -o main.o      # .c → .o trực tiếp
gcc main.c lib.c -o app -I.  # build nhiều file, -I. tìm header
```

### Cú pháp Rule

```makefile
target: prerequisites
<TAB>recipe          # PHẢI là TAB, không phải spaces!
```

### Biến

```makefile
NAME = VALUE         # gán đệ quy
NAME := VALUE        # gán tức thời
NAME += VALUE        # nối thêm
$(NAME) hoặc ${NAME} # gọi biến
```

### Automatic Variables

```makefile
$@   # tên target
$<   # prerequisite đầu tiên
$^   # tất cả prerequisites
$?   # prerequisites mới hơn target
$+   # như $^ nhưng giữ trùng lặp
$*   # phần gốc (stem) tên file
$%   # archive member
```

### Wildcards & Hàm

```makefile
%.o : %.c                              # pattern rule
*.c   ?   [...]                        # wildcard ký tự
$(wildcard $(DIR)/*)                   # lấy danh sách file
$(foreach var, list, text)             # lặp
$(notdir path/file.c)  → file.c        # bỏ đường dẫn
$(subst from,to,text)                  # thay chuỗi
```

### Tìm file đa thư mục

```makefile
CFLAGS = -I inc          # nơi tìm .h
VPATH  = src             # nơi tìm .c (mọi loại)
vpath %.c $(SRC_DIRS)    # nơi tìm riêng .c
vpath %.h $(INC_DIRS)    # nơi tìm riêng .h
```

### PHONY chuẩn

```makefile
.PHONY: all clean install distclean TAGS info check
```

### In biến (debug)

```makefile
print-%:
	@echo $($(subst print-,,$@))
# Dùng: make print-TÊN_BIẾN
```

### Nhúng (ARM / STM32)

```bash
# Compiler
arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -std=gnu11 -Ox -I$(INC)
# Linker
arm-none-eabi-ld -T $(LINKER_FILE) -Wl,-Map=out.map -nostdlib
# Objcopy
objcopy.exe -O ihex file.elf file.hex
# Nạp ST-LINK
ST-LINK_CLI.exe -ME
ST-LINK_CLI.exe -p file.hex 0x08000000
ST-LINK_CLI.exe -rst
```

### Nâng cao

```makefile
ifeq ($(MODULE),)
    $(error export MODULE before starting tests)
endif
include <dir/file>        # chèn makefile khác
gcc -DDEBUG ...           # define macro từ command line
```

---

# 🎓 LỜI KẾT

> 🛠️ Makefile không khó — cốt lõi chỉ là **`target : prerequisites` + `recipe` (thụt TAB)**. Phần còn lại là các công cụ giúp **tổng quát hóa** để không phải sửa tay khi dự án lớn lên.

### Lộ trình nắm vững Makefile

```
┌─────────────────────────────────────────────────────┐
│ 1. Hiểu BUILD PROCESS (.c → .i → .s → .o → .exe)     │
│    → gốc rễ của mọi thứ, đặc biệt với nhúng          │
├─────────────────────────────────────────────────────┤
│ 2. Thành thạo GCC command line (-E -S -c -o -I)      │
├─────────────────────────────────────────────────────┤
│ 3. Viết Rule cơ bản (nhớ TAB!) + PHONY               │
├─────────────────────────────────────────────────────┤
│ 4. Biến + Automatic Variables + Pattern Rule         │
├─────────────────────────────────────────────────────┤
│ 5. Đa thư mục: VPATH + foreach + wildcard + notdir   │
├─────────────────────────────────────────────────────┤
│ 6. Áp dụng cho Vi điều khiển (ARM/STM32)             │
├─────────────────────────────────────────────────────┤
│ 7. Nâng cao: ifeq/export/include → tái sử dụng       │
└─────────────────────────────────────────────────────┘
```

### Lời khuyên

1. **Nhớ TAB, đừng dùng spaces** — lỗi #1 của người mới với Makefile.
2. **Hiểu Build Process trước** — Makefile chỉ là tự động hóa các lệnh GCC, hiểu GCC thì viết Makefile rất nhẹ.
3. **Tổng quát hóa từ từ** — bắt đầu bằng Makefile viết cứng, rồi thay dần bằng biến, pattern rule, foreach.
4. **Dùng `make print-BIẾN`** để debug khi biến không ra giá trị mong muốn.
5. **Với nhúng**: nắm chắc vai trò của **Linker Script (.ld)** và **Locator** — đây là điểm khác biệt cốt lõi so với build trên PC.

### Tài nguyên học thêm

- 🌐 [GNU Make Manual](https://www.gnu.org/software/make/manual/make.html) — tài liệu chính thức, đầy đủ nhất
- 🌐 [github.com/nghia12a1-t-ara/makefile](https://github.com/nghia12a1-t-ara/makefile) — source code mẫu (khóa Makefile Course)
- 🌐 [github.com/Leminuos/makefile](https://github.com/Leminuos/makefile) — Makefile tham khảo
- 🔧 GNU ARM Toolchain — Compiler cho chip ARM
- 🔧 ST-LINK Utility (STSW-LINK004) — nạp code STM32

---

> 📝 *Tài liệu được tổng hợp từ 3 nguồn (ghi chú lý thuyết cá nhân + slide Makefile Course của Nguyễn Văn Nghĩa + vở viết tay) để học tập và lưu trữ. Nội dung khóa gốc thuộc về tác giả **Nguyễn Văn Nghĩa** (Nhóm Lập trình điện tử) và GNU Make documentation.*
