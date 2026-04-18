# HƯỚNG DẪN LÀM VIỆC NHÓM VỚI GITHUB VÀ VS CODE

## Dành cho người mới bắt đầu (chưa biết gì)

---

## MỤC LỤC
1. [Cài đặt phần mềm](#1-cài-đặt-phần-mềm)
2. [Tạo tài khoản GitHub](#2-tạo-tài-khoản-github)
3. [Clone dự án về máy](#3-clone-dự-án-về-máy)
4. [Cấu hình VS Code cho ESP32](#4-cấu-hình-vs-code-cho-esp32)
5. [Quy trình làm việc nhóm](#5-quy-trình-làm-việc-nhóm)
6. [Các lệnh Git cơ bản](#6-các-lệnh-git-cơ-bản)
7. [Xử lý lỗi thường gặp](#7-xử-lý-lỗi-thường-gặp)

---

## 1. CÀI ĐẶT PHẦN MỀM

### 1.1. Tải và cài VS Code

**VS Code** là phần mềm soạn thảo code (thay thế Arduino IDE)

1. Vào trang: https://code.visualstudio.com/
2. Click nút **"Download for Windows"**
3. Mở file vừa tải, cài đặt như bình thường (next, next, finish)

### 1.2. Cài đặt Git

**Git** là công cụ để đồng bộ code với GitHub

1. Vào trang: https://git-scm.com/download/win
2. Tải file .exu về
3. Chạy cài đặt, **chọn mặc định hết** (next, next, finish)

### 1.3. Cài đặt PlatformIO (trong VS Code)

**PlatformIO** là phần mềm giúp nạp code lên ESP32

1. Mở VS Code
2. Nhấn **Ctrl + Shift + X** (mở Extension)
3. Gõ tìm: **"PlatformIO IDE"**
4. Chọn kết quả đầu tiên → Click **"Install"**
5. Chờ cài đặt xong (khoảng 2-3 phút)
6. Restart VS Code

---

## 2. TẠO TÀI KHOẢN GITHUB

### 2.1. Đăng ký

1. Vào trang: https://github.com/
2. Nhập:
   - **Username**: tên bạn muốn (vd: nguyenvana)
   - **Email**: email của bạn
   - **Password**: mật khẩu
3. Click **"Sign up for GitHub"**
4. Xác nhận email (mở email, click link xác nhận)

### 2.2. Gửi tên GitHub cho trưởng nhóm

Sau khi có tài khoản, **gửi username GitHub của bạn** cho trưởng nhóm để được thêm vào dự án.

### 2.3. Tạo Personal Access Token (dùng thay mật khẩu)

1. Click avatar góc phải → **Settings**
2. Cuộn xuống → **Developer settings**
3. **Personal access tokens** → **Tokens (classic)**
4. **Generate new token** → **Generate new token (classic)**
5. Đặt tên: `esp32_token`
6. **Tick chọn `repo`** (quan trọng!)
7. Cuộn xuống → **Generate token**
8. **COPY NGAY TOKEN NÀY** (dạng `ghp_xxxxx`) và lưu lại

---

## 3. CLONE DỰ ÁN VỀ MÁY

### 3.1. Mở VS Code

### 3.2. Clone repository

1. Nhấn **Ctrl + Shift + P** (mở Command Palette)
2. Gõ: **"Git: Clone"**
3. Dán URL repo: `https://github.com/minhbinhtran-semi/Controlling_car.git`
4. Chọn thư mục lưu (vd: `D:\` hoặc `Desktop`)
5. Khi được hỏi đăng nhập:
   - **Username**: GitHub username của bạn
   - **Password**: **Dán token** đã tạo ở bước 2.3

### 3.3. Mở project

1. Khi clone xong, VS Code hỏi **"Open repository?"** → Chọn **Open**
2. Hoặc: **File → Open Folder** → Chọn thư mục vừa clone

---

## 4. CẤU HÌNH VS CODE CHO ESP32

### 4.1. Cắm ESP32 vào máy tính

- Dùng dây USB cắm ESP32 vào máy
- Lần đầu, máy sẽ tự cài driver

### 4.2. Chọn đúng cổng COM

1. Nhìn góc dưới cùng VS Code → Thanh màu xanh
2. Click biểu tượng **🔌** (Port) → Chọn cổng COM của ESP32
   (VD: COM3, COM4, COM5)

### 4.3. Nạp code lên ESP32

- Nhìn thanh màu xanh dưới cùng
- Click nút **→ (Upload)** (mũi tên phải)
- Chờ upload xong (khoảng 10-20 giây)

**Kết quả thành công:**
[SUCCESS] Upload complete

text

---

## 5. QUY TRÌNH LÀM VIỆC NHÓM

### SƠ ĐỒ LUỒNG LÀM VIỆC:
main (code chính, luôn ổn định)
│
├── feature/mpu6050 (bạn A làm cảm biến)
├── feature/motor (bạn B làm động cơ)
└── feature/ble (bạn C làm kết nối)

text

### 5.1. LẤY CODE MỚI NHẤT (LÀM ĐẦU TIÊN MỖI LẦN)

```bash
git checkout main
git pull origin main
5.2. TẠO NHÁNH RIÊNG (MỖI TÍNH NĂNG 1 NHÁNH)
bash
git checkout -b feature/ten_tinh_nang
Ví dụ tên nhánh:

feature/mpu6050 (cho cảm biến)

feature/motor (cho động cơ)

feature/ble (cho bluetooth)

feature/espnow (cho ESP-NOW)

fix/ten_loi (sửa lỗi)

5.3. CODE VÀ COMMIT
Sửa code trong file src/main.cpp

Lưu file (Ctrl + S)

Kiểm tra thay đổi:

bash
git status
Thêm file vào git:

bash
git add .
Commit (lưu lại):

bash
git commit -m "mô tả rõ thay đổi"
Ví dụ commit message tốt:

text
✅ "add: đọc dữ liệu từ MPU6050"
✅ "fix: sửa lỗi động cơ chạy ngược chiều"
✅ "update: tăng tốc độ gửi dữ liệu lên 50Hz"
❌ "sua code"
❌ "fix"
5.4. PUSH LÊN GITHUB
bash
git push -u origin feature/ten_tinh_nang
5.5. TẠO PULL REQUEST (YÊU CẦU DUYỆT CODE)
Mở trình duyệt vào repo GitHub

Click tab "Pull requests"

Click "New pull request"

Chọn:

base: main

compare: feature/ten_tinh_nang (nhánh của bạn)

Click "Create pull request"

Điền mô tả:

text
## Thay đổi
- Thêm chức năng đọc MPU6050
- Gửi dữ liệu qua BLE

## Kiểm tra
- [ ] Code chạy ổn định
Click "Create pull request"

5.6. SAU KHI ĐƯỢC DUYỆT (TRƯỞNG NHÓM MERGE XONG)
bash
git checkout main
git pull origin main
git branch -d feature/ten_tinh_nang
6. CÁC LỆNH GIT CƠ BẢN (TỔNG HỢP)
Lệnh	Ý nghĩa	Khi nào dùng
git clone <url>	Tải dự án về máy	Lần đầu lấy code
git checkout main	Chuyển sang nhánh main	Trước khi tạo nhánh mới
git pull origin main	Lấy code mới nhất	Mỗi khi bắt đầu làm
git checkout -b <tên>	Tạo nhánh mới	Bắt đầu tính năng mới
git status	Xem file đã thay đổi	Trước khi commit
git add .	Thêm tất cả file	Trước khi commit
git commit -m "..."	Lưu lại thay đổi	Sau khi add
git push -u origin <tên>	Đẩy lên GitHub	Sau khi commit
git branch	Xem danh sách nhánh	Kiểm tra đang ở nhánh nào
7. XỬ LÝ LỖI THƯỜNG GẶP
LỖI 1: "fatal: not a git repository"
Nguyên nhân: Đang ở sai thư mục

Cách sửa:

bash
cd D:\Controlling_car
LỖI 2: "Updates were rejected"
Nguyên nhân: Code trên GitHub mới hơn code trong máy

Cách sửa:

bash
git pull origin main
LỖI 3: "Please tell me who you are"
Nguyên nhân: Chưa cấu hình tên và email

Cách sửa:

bash
git config --global user.name "ten_cua_ban"
git config --global user.email "email_cua_ban"
LỖI 4: Upload không thấy cổng COM
Cách sửa:

Cắm lại ESP32

Cài driver CP210x (tìm trên Google)

Restart VS Code

Chạy:

bash
git add .
git commit -m "resolve conflict"
git push
TÓM TẮT QUY TRÌNH (CHO MỖI LẦN LÀM VIỆC)
bash
# 1. Lấy code mới nhất
git checkout main
git pull origin main

# 2. Tạo nhánh mới
git checkout -b feature/ten_tinh_nang

# 3. Code, sửa file...

# 4. Lưu và commit
git add .
git commit -m "mô tả thay đổi"

# 5. Push lên GitHub
git push -u origin feature/ten_tinh_nang

# 6. Lên GitHub tạo Pull Request