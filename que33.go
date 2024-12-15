package main

import (
    "fmt"
    "time"
)

// 判断是否是闰年
func isLeapYear(year int) bool {
    if year%400 == 0 {
        return true
    } else if year%100 == 0 {
        return false
    } else if year%4 == 0 {
        return true
    }
    return false
}

// 获取某年某月的天数
func getDaysInMonth(year, month int) int {
    switch month {
    case 1, 3, 5, 7, 8, 10, 12:
        return 31
    case 4, 6, 9, 11:
        return 30
    case 2:
        if isLeapYear(year) {
            return 29
        }
        return 28
    default:
        return 0
    }
}

// 获取某年某月的第一天是星期几
func getFirstDayOfMonth(year, month int) time.Weekday {
    return time.Date(year, time.Month(month), 1, 0, 0, 0, 0, time.UTC).Weekday()
}

// 打印某年某月的日历
func printCalendar(year, month int) {
    daysInMonth := getDaysInMonth(year, month)
    firstDay := getFirstDayOfMonth(year, month)

    // 打印头部信息
    fmt.Printf("    %d年 %d月\n", year, month)
    fmt.Println("日 一 二 三 四 五 六")

    // 打印前置空格
    for i := 0; i < int(firstDay); i++ {
        fmt.Print("    ")
    }

    // 打印日期
    for day := 1; day <= daysInMonth; day++ {
        fmt.Printf("%2d ", day)
        if (day+int(firstDay))%7 == 0 {
            fmt.Println()
        }
    }
    if (daysInMonth+int(firstDay))%7 != 0 {
        fmt.Println()
    }
}

func main() {
    var year, month int

    fmt.Print("请输入年份: ")
    fmt.Scan(&year)
    fmt.Print("请输入月份: ")
    fmt.Scan(&month)

    if month < 1 || month > 12 {
        fmt.Println("月份必须在1到12之间")
        return
    }

    printCalendar(year, month)
}
