# Псевдокод — №27 Зогсоолын төлбөр

```
START Main
  total = 0, longestIdx = 0
  DO: INPUT n WHILE n < 1 OR n > 10            // оролтын шалгалт
  FOR i = 0 TO n-1
     DO
        DO INPUT inH  WHILE inH < 0 OR inH > 23
        DO INPUT inM  WHILE inM < 0 OR inM > 59
        DO INPUT outH WHILE outH < 0 OR outH > 23
        DO INPUT outM WHILE outM < 0 OR outM > 59
        minutes = (outH*60 + outM) - (inH*60 + inM)
        IF minutes < 0 THEN PRINT "Aldaa"
     WHILE minutes < 0
     fee = CALL CalcFee(minutes)                 // Function (Call блок)
     хадгалах: entryT[i], exitT[i], mins[i], fees[i]
     total = total + fee
     IF minutes > mins[longestIdx] OR (minutes == mins[longestIdx] AND fee > fees[longestIdx])
        longestIdx = i                           // хайлт: хамгийн удаан зогссон
  END FOR
  PRINT толгой мөр
  FOR i = 0 TO n-1  PRINT мөр (№, орсон, гарсан, минут, төлбөр)
  PRINT total, longestIdx+1, дундаж минут
END

FUNCTION CalcFee(minutes)
  IF minutes <= 30   RETURN 0
  ELSE IF minutes <= 60  RETURN 1000
  ELSE IF minutes <= 180 RETURN 3000
  ELSE IF minutes <= 480 RETURN 6000
  ELSE RETURN 10000
```
