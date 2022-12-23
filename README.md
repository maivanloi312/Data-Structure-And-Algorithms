# Data-Structure-And-Algorithms (Thi Trắc Nghiệm)
# Tóm tắt
Ngôn ngữ C++
Ta tổ chức các danh sách sau:
Danh sách môn học: mảng con trỏ (MAMH (C15), TENMH).
Danh sách Lop : danh sách tuyến tính (MALOP, TENLOP, con trỏ): con trỏ sẻ trỏ đến danh sách sinh viên thuộc lớp đó.
Danh sách sinh viên : danh sách liên kết đơn (MASV, HO, TEN, PHAI, password, con trỏ): con trỏ sẽ trỏ đến điểm các môn đã thi trắc nghiệm.
Danh sách Điểm thi (danh sách liên kết đơn) (Mamh, Diem).
Danh sách Câu hỏi thi (cây nhị phân tìm kiếm cân bằng với key = Id) (Id, Mă MH, Nội dung, A, B, C, D, Đáp án); trong đó A, B, C, D là 4 chọn lựa tương ứng với nội dung câu hỏi.
Chương trình có các chức năng sau : a/ Đăng nhập dựa vào mã sinh viên, password. Nếu tài khoản đăng nhập là GV, pass là GV thì sẽ có toàn quyền . b/ NhapLop c/ In ds lớp d/ Nhập sinh viên của lớp : nhập vào mã lớp trước, sau đó nhập các sinh viên vào lớp đó. e/ Nhập môn học: cho phép cập nhật (thêm / xóa / hiệu chỉnh ) thông tin của môn học f/ Nhập câu hỏi thi (Id là số ngẫu nhiên do chương trình tự tạo ) g/ Thi Trắc nghiệm ( trước khi thi hỏi người thi môn thi, số câu hỏi thi, số phút thi-sau đó lấy ngẫu nhiên các câu hỏi trong danh sách câu hỏi thi của môn; h/ In chi tiết các câu hỏi đã thi 1 môn học của 1 sinh viên, i/ In bảng điểm thi trắc nghiệm môn học của 1 lớp (nếu có sinh viên chưa thi thì ghi “Chưa thi”. Lưu ý: Chương trình cho phép lưu các danh sách vào file; Kiểm tra các điều kiện làm dữ liệu bị sai. Sinh viên có thể tự thiết kế thêm danh sách để đáp ứng yêu cầu của đề tài.
# Yêu cầu:
Cài đặt IDE Dev-C++
Kiến thức: Cấu trúc dữ liệu mảng, Danh sách liên kết, Cây nhị phân, Giải thuật sắp xếp, Giải thuật tìm kiếm
Khóa học kiến nghị: https://codelearn.io/learning/cau-truc-du-lieu-va-giai-thuat
# Cách sử dụng:
Chạy file Project.dev và nhấn F11 để IDE biên dịch và chạy chương trình
# Những vấn đề cần cải thiện:
- Cải thiện thuật toán đa luồng ở đồng hồ thi.
- Thêm tính năng có thể tiếp tục thi lại bài thi trong trường khi đang làm bài thì xảy ra sự cố như mất điện, máy lỗi,...
- Thay đổi thuật toán lấy câu hỏi ngẫu nhiên trong bộ đề để tạo thành bài thi giúp chương trình tiết kiệm tài nguyên khi lưu bài thi của người thi và truy xuất nhanh hơn
- Cải thiện thuật lấy câu hỏi trong bộ đề tối ưu hơn (Ví dụ: Bộ đề có 10000 câu, lấy ngẫu nhiên các câu hỏi yêu cầu các câu hỏi thi không được trùng nhau, khi số câu hỏi đã lấy tăng tới 9000 thì sẽ gặp tình trạng lấy random vào câu hỏi đã lấy, lúc này phải luân phiên chạy lại từ đầu thuật toán cho đến khi tìm được câu hỏi khác chưa được lấy, rất tốn thời gian). Gợi ý: Khi câu hỏi đã lấy tăng tới 9000 sẽ bắt đầu chạy thuật toán tìm phần tử chưa xuất hiện mà không chạy thuật toán lấy ngẫu nhiên nữa.
- Phần Vào thi nên nhập Tên môn thi, không nên nhập Mã môn thi.
# Tác giả:
Giao diện: Huỳnh Tuấn Kiệt
Chức năng: Mai Văn Lợi
Và chúng em xin cảm ơn thầy Lưu Nguyễn Kỳ Thư đã hướng dẫn chúng em thực hiện đồ án này!
# Một số hình ảnh của chương trình
Đăng nhập
![Screenshot (2)](https://user-images.githubusercontent.com/85224148/209391725-e77bba0e-524e-4fe6-815a-08713fa31240.png)
Thêm sinh viên vào lớp dành cho giảng viên
![Screenshot (4)](https://user-images.githubusercontent.com/85224148/209391927-498881da-dff1-4306-9122-057d81d27c1c.png)
Thêm câu hỏi thi dành cho giảng viên
![Screenshot (3)](https://user-images.githubusercontent.com/85224148/209391837-417e980d-adca-4018-a27b-ee138bc3e268.png)
Vào thi dành cho sinh viên
![Screenshot (5)](https://user-images.githubusercontent.com/85224148/209391992-01c1ae4b-4f82-41bc-acd9-17aac3de8089.png)
Làm bài thi
![Screenshot (6)](https://user-images.githubusercontent.com/85224148/209392053-47486f78-c941-4b09-ba28-1b33d0018de5.png)


