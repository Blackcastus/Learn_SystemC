# Learn systemC

## Part1 Hello systemC

Add path library systemc
Run hello systemc

## Part2 Module

Create module A & module B
not input, not output

## Part3 Process
1. SC_METHOD:

* SC_METHOD là một hàm hoặc phương thức trong SystemC được gọi bởi hệ thống chạy theo sự kiểm soát của sự kiện (event-driven). Nghĩa là nó sẽ được kích hoạt chỉ khi sự kiện liên quan xảy ra.
* SC_METHOD không thể sử dụng vòng lặp vô hạn, vì nó có thể dẫn đến xung đột trong hệ thống chạy sự kiện.
* SC_METHOD thích hợp cho các tác vụ đơn giản, không đòi hỏi thời gian chính xác và không cần đồng bộ.

2. SC_THREAD:

* SC_THREAD là một loại quy trình trong SystemC được quản lý bởi hệ điều hành thời gian thực. Nó được thực hiện như một luồng độc lập và có thể chạy song song với các luồng khác.
* SC_THREAD có thể chứa vòng lặp vô hạn và được sử dụng để mô phỏng các quá trình không đồng bộ và xử lý theo dòng thời gian.
* SC_THREAD sử dụng các lệnh cơ bản như wait(), wait(SC_ZERO_TIME), hoặc wait(some_event) để đồng bộ và chuyển đổi giữa các trạng thái.

3. SC_CTHREAD:

* SC_CTHREAD là một loại quy trình trong SystemC tương tự như SC_THREAD, nhưng với một số tính năng bổ sung.
* SC_CTHREAD có thể sử dụng cơ chế cảnh báo dựa trên thời gian (timed wait) để chuyển đổi giữa các trạng thái, ví dụ: wait(10, SC_NS) để đợi trong 10 nanosecond.
* SC_CTHREAD cũng sử dụng các lệnh cơ bản như wait(), wait(SC_ZERO_TIME), hoặc wait(some_event) để đồng bộ và chuyển đổi giữa các trạng thái.