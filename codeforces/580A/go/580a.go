package main

import (
    "fmt"
    //"strings"
    "bufio"
    "os"
    "strconv"
    "bytes"
    "io"
    )

func read_line() bytes.Buffer {
    reader := bufio.NewReader(os.Stdin)
    var buf bytes.Buffer
    /*
    for {
        line, prefix, err := reader.ReadLine()
        if len(line) > 0 {
            buf.Write(line)
        } else {
            break
        }
        if err != nil || err == io.EOF {
            break
        }
        if !prefix {
            fmt.Println("!prefix")
            break
        }
    }
    */
    for {
        p := make([]byte, 1024)
        bytes, err := reader.Read(p)
        if err == io.EOF || bytes == 0 {
            break
        }
        buf.Write(p)
        fmt.Println(p)
    }

    return buf
}

func read_line_scanner() string {
    scanner := bufio.NewScanner(os.Stdin)
    var line string
    for scanner.Scan() {
        fmt.Println(scanner.Text())
        line += scanner.Text()
    }

    return line
}

func main() {
    var n, i uint
    fmt.Scanf("%d\n", &n)

    seq := make([]int64, n, n)
    /*reader := bufio.NewReader(os.Stdin)
    for i = 0; i < n; i++ {
        str, _ := reader.ReadSlice(' ')
        seq[i], _ = strconv.ParseInt(string(str), 10, 64)
        fmt.Print(i, "-", str, ",")
    }*/
    bs := bufio.NewScanner(os.Stdin)
    bs.Split(bufio.ScanWords)

    for i = 0; i < n; i++ {
        bs.Scan()
        seq[i], _ = strconv.ParseInt(bs.Text(), 10, 64)
    }

/*
    var buf bytes.Buffer
    buf = read_line()

    line := buf.String()
    //line := read_line()
    fmt.Println("line len: ", len(line))

    strseq := strings.Split(line, " ")
    fmt.Println("strseq len: ", len(strseq))

    seq := make([]int64, n, n)
    for i = 0; i < n; i++ {
        seq[i], _ = strconv.ParseInt(strseq[i], 10, 64)
    }
*/

    //reader := bufio.NewReader(os.Stdin)
    //buf, _, _ := reader.ReadLine()

    //fmt.Println("buf len: ", len(buf))

    //line := string(buf)
    //fmt.Println("line len: ", len(line))

    //strseq := strings.Split(line, " ")
    //fmt.Println("strseq len: ", len(strseq))

    //line := read_line()
    //strseq := strings.Split(line, " ")

    //seq := make([]int64, n, n)
    ////for i = 0; i < n; i++ {
    //    seq[i], _ = strconv.ParseInt(strseq[i], 10, 64)
    //}

    maxlen := 1
    cur := 1
    for i = 1; i < n; i++ {
        if seq[i] >= seq[i-1] {
            cur++
        } else {
            cur = 1
        }

        if maxlen < cur {
            maxlen = cur
        }
    }

    fmt.Println(maxlen)
}

