# Giới thiệu về ISD1820
ISD1820 là một IC ghi âm và phát lại đoạn âm thanh đơn đoạn (single-chip) sử dụng công nghệ lưu trữ không mất dữ liệu. Module tích hợp sẵn micro, bộ tiền khuếch đại và mạch lái loa trực tiếp.

## Thông số kỹ thuật
*   **Điện áp hoạt động:** 3V - 5V DC (Sử dụng **3.3V** để đồng bộ logic với ESP32).
*   **Thời gian ghi âm:** 10 - 20 giây (Mặc định 10 giây cho chất lượng âm thanh 8kHz tốt nhất).
*   **Công suất loa:** 0.5W (Trở kháng 8Ω).
*   **Chế độ điều khiển:** Tích cực mức CAO (**Active HIGH**).
*   **Tính năng đặc biệt:** Hỗ trợ chế độ Feed-Through (FT) để biến module thành loa phóng thanh (Megaphone).

# Sơ đồ kết nối (Active Control Wiring)

Hệ thống được cấu hình để ESP32 điều khiển chủ động các chân chức năng thay vì sử dụng nút nhấn vật lý.

| Chân ISD1820 | Chân ESP32 | Chức năng (Góc nhìn ESP32) |
| :--- | :--- | :--- |
| **VCC** | 3.3V | Cấp nguồn |
| **GND** | GND | Tiếp địa |
| **REC** | GPIO 13 | Kích hoạt ghi âm (Active HIGH) |
| **P-E (PLAYE)** | GPIO 12 | Phát lại toàn bộ (Edge Trigger) |
| **P-L (PLAYL)** | GPIO 14 | Phát lại theo mức (Level Trigger) |
| **FT** | GPIO 27 | Chế độ Megaphone (Nói trực tiếp qua Micro) |

# Tính năng mã nguồn
Mã nguồn chuyển đổi các chân GPIO sang chế độ `OUTPUT`, cho phép người dùng điều khiển module thông qua giao diện dòng lệnh (CLI) trên Serial Monitor.

## Các tập lệnh điều khiển (Baudrate 115200):
| Lệnh | Hành động | Mô tả |
| :--- | :--- | :--- |
| `REC` | Ghi âm | ESP32 xuất mức HIGH vào chân REC. |
| `STOP` | Dừng | Đưa tất cả các chân điều khiển về mức LOW. |
| `PLAYE` | Phát toàn bộ | Kích một xung 200ms vào chân P-E để phát hết bản tin. |
| `PLAYL` | Phát tức thời | Duy trì mức HIGH tại chân P-L để phát âm thanh. |
