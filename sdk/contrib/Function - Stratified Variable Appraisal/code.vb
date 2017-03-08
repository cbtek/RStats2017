Public TableSheetName As String

   Function AddWorksheet()

    Dim Sheet As Variant
    
    Sheets.Add
    Sheet = ""
    On Error GoTo trap
    ActiveSheet.Name = TableSheetName & Sheet
    Exit Function
trap:
       If Sheet = "" Then Sheet = 1
       Sheet = Sheet + 1
       Resume

End Function

Private Sub CommandButton1_Click()
   GoSub INITIALIZATION
   GoSub SUMVALUES
   GoSub PROCESS
   GoSub PRINTOUT
   Exit Sub
'*****************************************************
INITIALIZATION:
'*****************************************************
   Dim c(1000) As Double
   Dim D(1000) As Double
   Dim TemporVariables(100) As Double
   Dim lowval As Double
   Dim highval As Double
   Dim tval As Double
   Dim xval As Double
   Dim eps As Double
   Dim diff As Double
   Dim tvallast As Double
   Dim tempval As Double
   Dim Number As Integer
   Dim NumTerms As Integer
   Dim I As Integer
   Dim J As Integer
   Dim SUMEXAM As Double
   Dim SMPLSIZE(100) As Long
   Dim SampleSize(100)
   Dim STRTAMT(100, 3) As Double
   Dim SQRAMT(100, 3) As Double
   Dim CUBEAMT(100, 3) As Double
   Dim QUADAMT(100, 3) As Double
   Dim NONZERO(100, 3) As Long
   Dim UNIVNBR(100) As Long
   Dim MEAN(100, 3) As Double
   Dim PNTEST(100, 3) As Double
   Dim STDDEV(100, 3) As Double
   Dim STDERR(100, 3) As Double
   Dim SKEWAMT(100, 3) As Double
   Dim KURTAMT(100, 3) As Double
   Dim PRCISN(100, 3, 2) As Double
   Dim LWRLMT(100, 3, 2) As Double
   Dim UPRLMT(100, 3, 2) As Double
   Dim PRNTFLAG(100) As String
   Dim Skew(100, 3) As Double
   Dim KURTOSIS(100, 3) As Double
   Dim VSTANDARDERR(100, 3) As Double
   Dim VMEAN(100, 3) As Double
   Dim VSTDDEV(100, 3) As Double
   Dim VLWRQTY80(100, 3) As Double
   Dim VLWRQTY90(100, 3) As Double
   Dim VLWRQTY95(100, 3) As Double
   Dim VUPRQTY80(100, 3) As Double
   Dim VUPRQTY90(100, 3) As Double
   Dim VUPRQTY95(100, 3) As Double
   Dim VPREC80(100, 3) As Double
   Dim VPREC90(100, 3) As Double
   Dim VPREC95(100, 3) As Double
   Dim VUNIV(100) As Long
   Dim VUNIVNBR(100) As Long
   Dim VSAMPLESIZE(100) As Long
   Dim VPROJNUMBER(100, 3)
   Dim ExamValue(100, 10000)
   Dim AudValue(100, 10000)
   Dim DiffValue(100, 10000)
   Dim Tvalue80(100)
   Dim Tvalue90(100)
   Dim Tvalue95(100)
   ZVAL80 = 1.281551565545
   ZVAL90 = 1.644853626951
   ZVAL95 = 1.95996398454
   If frmInput.optExam.Value = True Then FFORMAT% = 1
   If frmInput.optAud.Value = True Then FFORMAT% = 2
   If frmInput.optDiff.Value = True Then FFORMAT% = 3
   If frmInput.optExamAud.Value = True Then FFORMAT% = 4
   If frmInput.optExamDiff.Value = True Then FFORMAT% = 5
   If frmInput.optAudDiff.Value = True Then FFORMAT% = 6
'****************************************************
READINSAMPLERESULTS:
'****************************************************
  NumOfStrata = frmInput.txtStrata.Text
  For I = 1 To NumOfStrata
      ActiveWorkbook.Sheets("Strata Info").Activate
      SampleSize(I) = ActiveSheet.Cells(4 + I, 3)
      VUNIVNBR&(I) = ActiveSheet.Cells(4 + I, 2)
      ActiveWorkbook.Sheets("Data").Activate
      If FFORMAT% = 1 Then
         ColVal = 2 * I
         For J = 1 To SampleSize(I)
             Tempor$ = ActiveSheet.Cells(5 + J, ColVal)
             If IsNumeric(Tempor$) = False Then
                MsgBox ("The examined value in row " & Str(5 + J) & " is not a valid number.")
                Exit Sub
             Else
                ExamValue(I, J) = Tempor$
                SMPLSIZE&(0) = SMPLSIZE&(0) + 1
                SUMEXAM = SUMEXAM + ExamValue(I, J)
                If ExamValue(I, J) <> 0 Then SUMNONZERO = SUMNONZERO + 1
             End If
         Next J
      End If
      If FFORMAT% = 2 Then
         ColVal = 2 * I
         For J = 1 To SampleSize(I)
             Tempor$ = Cells(5 + J, ColVal)
             If IsNumeric(Tempor$) = False Then
                MsgBox ("The audited value in row " & Str(5 + J) & " is not a valid number.")
                Exit Sub
             Else
                AudValue(I, J) = Tempor$
                SMPLSIZE&(0) = SMPLSIZE&(0) + 1
                SUMEXAM = SUMEXAM + AudValue(I, J)
                If AudValue(I, J) <> 0 Then SUMNONZERO = SUMNONZERO + 1
            End If
         Next J
      End If
      If FFORMAT% = 3 Then
         ColVal = 2 * I
         For J = 1 To SampleSize(I)
             Tempor$ = Cells(5 + J, ColVal)
             If IsNumeric(Tempor$) = False Then
                MsgBox ("The difference value in row " & Str(5 + J) & " is not a valid number.")
                Exit Sub
             Else
                DiffValue(I, J) = Tempor$
                SMPLSIZE&(0) = SMPLSIZE&(0) + 1
                SUMEXAM = SUMEXAM + DiffValue(I, J)
                If DiffValue(I, J) <> 0 Then SUMNONZERO = SUMNONZERO + 1
             End If
         Next J
      End If
      If FFORMAT% = 4 Then
         ColVal = 3 * I - 1
         For J = 1 To SampleSize(I)
             Tempor$ = Cells(5 + J, ColVal)
             If IsNumeric(Tempor$) = False Then
                MsgBox ("The examined value in row " & Str(5 + J) & " is not a valid number.")
                Exit Sub
             Else
                ExamValue(I, J) = Tempor$
             End If
         Next J
         For J = 1 To SampleSize(I)
             Tempor$ = Cells(5 + J, ColVal + 1)
             If IsNumeric(Tempor$) = False Then
                MsgBox ("The audited value in row " & Str(5 + J) & " is not a valid number.")
                Exit Sub
             Else
                AudValue(I, J) = Tempor$
             End If
         Next J
         For J = 1 To SampleSize(I)
             DiffValue(I, J) = ExamValue(I, J) - AudValue(I, J)
             SMPLSIZE&(0) = SMPLSIZE&(0) + 1
             SUMEXAM = SUMEXAM + ExamValue(I, J)
             SUMAUD = SUMAUD + AudValue(I, J)
             SUMDIFF = SUMDIFF + DiffValue(I, J)
         Next J
      End If
      If FFORMAT% = 5 Then
         ColVal = 3 * I - 1
         For J = 1 To SampleSize(I)
             Tempor$ = Cells(5 + J, ColVal)
             If IsNumeric(Tempor$) = False Then
                MsgBox ("The examined value in row " & Str(5 + J) & " is not a valid number.")
                Exit Sub
             Else
                ExamValue(I, J) = Tempor$
             End If
         Next J
         For J = 1 To SampleSize(I)
             Tempor$ = Cells(5 + J, ColVal + 1)
             If IsNumeric(Tempor$) = False Then
                MsgBox ("The difference value in row " & Str(5 + J) & " is not a valid number.")
                Exit Sub
             Else
                DiffValue(I, J) = Tempor$
             End If
         Next J
         For J = 1 To SampleSize(I)
             AudValue(I, J) = ExamValue(I, J) - DiffValue(I, J)
             SMPLSIZE&(0) = SMPLSIZE&(0) + 1
             SUMEXAM = SUMEXAM + ExamValue(I, J)
             SUMAUD = SUMAUD + AudValue(I, J)
             SUMDIFF = SUMDIFF + DiffValue(I, J)
         Next J
      End If
      If FFORMAT% = 6 Then
         ColVal = 3 * I - 1
         For J = 1 To SampleSize(I)
             Tempor$ = Cells(5 + J, ColVal)
             If IsNumeric(Tempor$) = False Then
                MsgBox ("The audited value in row " & Str(5 + J) & " is not a valid number.")
                Exit Sub
             Else
                AudValue(I, J) = Tempor$
             End If
         Next J
         For J = 1 To SampleSize(I)
             Tempor$ = Cells(5 + J, ColVal + 1)
             If IsNumeric(Tempor$) = False Then
                MsgBox ("The difference value in row " & Str(5 + J) & " is not a valid number.")
                Exit Sub
             Else
                DiffValue(I, J) = Tempor$
             End If
         Next J
         For J = 1 To SampleSize(I)
             ExamValue(I, J) = AudValue(I, J) + DiffValue(I, J)
             SMPLSIZE&(0) = SMPLSIZE&(0) + 1
             SUMEXAM = SUMEXAM + ExamValue(I, J)
             SUMAUD = SUMAUD + AudValue(I, J)
             SUMDIFF = SUMDIFF + DiffValue(I, J)
         Next J
      End If
  Next I
ENDREADS:
   Return
'--------SUM VALUES-------
SUMVALUES:
For STRTNBR% = 1 To NumOfStrata
  For I = 1 To SampleSize(STRTNBR%)
      If FFORMAT% > 3 Then GoTo FFORMATGT3
      If FFORMAT% = 1 Then tempval# = ExamValue(STRTNBR%, I)
      If FFORMAT% = 2 Then tempval# = AudValue(STRTNBR%, I)
      If FFORMAT% = 3 Then tempval# = DiffValue(STRTNBR%, I)
      STRTAMT#(STRTNBR%, 1) = STRTAMT#(STRTNBR%, 1) + tempval#
      SQRAMT#(STRTNBR%, 1) = SQRAMT#(STRTNBR%, 1) + tempval# ^ 2
      CUBEAMT#(STRTNBR%, 1) = CUBEAMT#(STRTNBR%, 1) + tempval# ^ 3
      QUADAMT#(STRTNBR%, 1) = QUADAMT#(STRTNBR%, 1) + tempval# ^ 4
      If tempval# <> 0 Then
          NONZERO&(STRTNBR%, 1) = NONZERO&(STRTNBR%, 1) + 1
      End If
FFORMATGT3:
      If FFORMAT% > 3 Then
         STRTAMT#(STRTNBR%, 1) = STRTAMT#(STRTNBR%, 1) + ExamValue(STRTNBR%, I)
         SQRAMT#(STRTNBR%, 1) = SQRAMT#(STRTNBR%, 1) + ExamValue(STRTNBR%, I) ^ 2
         CUBEAMT#(STRTNBR%, 1) = CUBEAMT#(STRTNBR%, 1) + ExamValue(STRTNBR%, I) ^ 3
         QUADAMT#(STRTNBR%, 1) = QUADAMT#(STRTNBR%, 1) + ExamValue(STRTNBR%, I) ^ 4
         If ExamValue(STRTNBR%, I) <> 0 Then
            NONZERO&(STRTNBR%, 1) = NONZERO&(STRTNBR%, 1) + 1
         End If
         STRTAMT#(STRTNBR%, 2) = STRTAMT#(STRTNBR%, 2) + AudValue(STRTNBR%, I)
         SQRAMT#(STRTNBR%, 2) = SQRAMT#(STRTNBR%, 2) + AudValue(STRTNBR%, I) ^ 2
         CUBEAMT#(STRTNBR%, 2) = CUBEAMT#(STRTNBR%, 2) + AudValue(STRTNBR%, I) ^ 3
         QUADAMT#(STRTNBR%, 2) = QUADAMT#(STRTNBR%, 2) + AudValue(STRTNBR%, I) ^ 4
         If AudValue(STRTNBR%, I) <> 0 Then
            NONZERO&(STRTNBR%, 2) = NONZERO&(STRTNBR%, 2) + 1
         End If
         STRTAMT#(STRTNBR%, 3) = STRTAMT#(STRTNBR%, 3) + DiffValue(STRTNBR%, I)
         SQRAMT#(STRTNBR%, 3) = SQRAMT#(STRTNBR%, 3) + DiffValue(STRTNBR%, I) ^ 2
         CUBEAMT#(STRTNBR%, 3) = CUBEAMT#(STRTNBR%, 3) + DiffValue(STRTNBR%, I) ^ 3
         QUADAMT#(STRTNBR%, 3) = QUADAMT#(STRTNBR%, 3) + DiffValue(STRTNBR%, I) ^ 4
         If DiffValue(STRTNBR%, I) <> 0 Then
            NONZERO&(STRTNBR%, 3) = NONZERO&(STRTNBR%, 3) + 1
         End If
      End If
  Next I
Next STRTNBR%
'------------DETERMINE SUMMARY TOTALS------
PRINTSUMMARYTOTALS:
SMPLSIZE&(0) = 0
STRTNBR% = NumOfStrata
For LOOP0% = 1 To STRTNBR%
    SMPLSIZE&(LOOP0%) = SampleSize(LOOP0%)
    SMPLSIZE&(0) = SMPLSIZE&(0) + SMPLSIZE&(LOOP0%)
    STRTAMT#(0, 1) = STRTAMT#(0, 1) + STRTAMT#(LOOP0%, 1)
    NONZERO&(0, 1) = NONZERO&(0, 1) + NONZERO&(LOOP0%, 1)
    If FFORMAT% > 3 Then
       STRTAMT#(0, 2) = STRTAMT#(0, 2) + STRTAMT#(LOOP0%, 2)
       STRTAMT#(0, 3) = STRTAMT#(0, 3) + STRTAMT#(LOOP0%, 3)
       NONZERO&(0, 2) = NONZERO&(0, 2) + NONZERO&(LOOP0%, 2)
       NONZERO&(0, 3) = NONZERO&(0, 3) + NONZERO&(LOOP0%, 3)
    End If
Next LOOP0%
Return
START HERE:
'*****************************************************
PROCESS:
'*****************************************************
STRTNBR% = frmInput.txtStrata.Text
VUNIV&(0) = 0
VSAMPLESIZE&(0) = 0
VUNIVNBR&(0) = 0
SMPLSIZE&(0) = 0
For Loop1% = 1 To STRTNBR%
   SMPLSIZE&(Loop1%) = SampleSize(Loop1%)
   SMPLSIZE&(0) = SMPLSIZE&(0) + SMPLSIZE&(Loop1%)
   VUNIV&(Loop1%) = VUNIVNBR&(Loop1%)
   VUNIV&(0) = VUNIV&(0) + VUNIV&(Loop1%)
   VSAMPLESIZE&(Loop1%) = SMPLSIZE&(Loop1%)
   VSAMPLESIZE&(0) = VSAMPLESIZE&(0) + SMPLSIZE&(Loop1%)
   VUNIVNBR&(0) = VUNIVNBR&(0) + VUNIVNBR&(Loop1%)
'---------CALCULATE MEANS--------
   For Loop2% = 1 To 3
       If SMPLSIZE&(Loop1%) > 0 And NONZERO&(Loop1%, Loop2%) > 0 Then
          MEAN#(Loop1%, Loop2%) = STRTAMT#(Loop1%, Loop2%) / SMPLSIZE&(Loop1%)
          VMEAN#(Loop1%, Loop2%) = MEAN#(Loop1%, Loop2%)
       End If
   Next Loop2%
'----------CALCULATE POINT ESTIMATES------
   For Loop2% = 1 To 3
       PNTEST#(Loop1%, Loop2%) = MEAN#(Loop1%, Loop2%) * VUNIVNBR&(Loop1%)
       PNTEST#(0, Loop2%) = PNTEST#(0, Loop2%) + PNTEST#(Loop1%, Loop2%)
       VPROJNUMBER(Loop1%, Loop2%) = PNTEST#(Loop1%, Loop2%)
   Next Loop2%
'---------CALCULATE CORRECTION FACTORS-------
   If VUNIVNBR&(Loop1%) > 1 Then
      SEFIN# = Sqr((VUNIVNBR&(Loop1%) - SMPLSIZE&(Loop1%)) / (VUNIVNBR&(Loop1%)))
   End If
'---------CALCULATE DEGREES OF FREEDOM-------
   Degrees# = SMPLSIZE&(Loop1%) - 1
'----------CALCULATE STANDARD DEVIATION-------
   For Loop2% = 1 To 3
       If STRTAMT#(Loop1%, Loop2%) <> 0 And SMPLSIZE&(Loop1%) > 1 Then
          temp1# = (STRTAMT#(Loop1%, Loop2%) ^ 2) / SMPLSIZE&(Loop1%)
          If temp1# < SQRAMT#(Loop1%, Loop2%) Then
             STDDEV#(Loop1%, Loop2%) = Sqr((SQRAMT#(Loop1%, Loop2%) - temp1#) / Degrees#)
          Else
            STDDEV#(Loop1%, Loop2%) = 0
          End If
          STDDEV#(0, Loop2%) = STDDEV#(0, Loop2%) + STDDEV#(Loop1%, Loop2%) ^ 2 * VUNIVNBR&(Loop1%) ^ 2
       End If
       VSTDDEV#(Loop1%, Loop2%) = STDDEV#(Loop1%, Loop2%)
   Next Loop2%
'----------CALCULATE STANDARD ERROR----------
   For Loop2% = 1 To 3
       If STDDEV#(Loop1%, Loop2%) <> 0 And SMPLSIZE&(Loop1%) > 1 Then
          STDERR#(Loop1%, Loop2%) = (STDDEV#(Loop1%, Loop2%) / Sqr(SMPLSIZE&(Loop1%))) * SEFIN#
          tempval# = VUNIVNBR&(Loop1%)
          tempval# = tempval# * (VUNIVNBR&(Loop1%) - SMPLSIZE&(Loop1%))
          tempval# = tempval# * (STDDEV#(Loop1%, Loop2%) ^ 2)
          tempval# = tempval# / SMPLSIZE&(Loop1%)
          TERMSE# = tempval#
'          TERMSE# = ((VUNIVNBR&(LOOP1%)) * (VUNIVNBR&(LOOP1%) - SMPLSIZE&(LOOP1%)) * (STDDEV#(LOOP1%, LOOP2%) ^ 2) / SMPLSIZE&(LOOP1%))
          STDERR#(0, Loop2%) = STDERR#(0, Loop2%) + TERMSE#
       End If
       VSTANDARDERR#(Loop1%, Loop2%) = STDERR#(Loop1%, Loop2%)
   Next Loop2%
'---------CALCULATE SAMPLING ERROR---------
   TEMP80# = 0
   TEMP90# = 0
   TEMP95# = 0
   If Degrees# > 3 Then GoTo TSetUp
   If Degrees# = 1 Then
      TEMP80# = 3.077683537175
      TEMP90# = 6.313751514675
      TEMP95# = 12.706204736175
   ElseIf Degrees# = 2 Then
      TEMP80# = 1.885618083164
      TEMP90# = 2.919985580354
      TEMP95# = 4.30265272975
   ElseIf Degrees# = 3 Then
      TEMP80# = 1.637744353696
      TEMP90# = 2.353363434802
      TEMP95# = 3.182446305284
   End If
   GoTo FindIntervals
'
'   Determine t-value
'
TSetUp:
   NumTerms = 100
   MaxIter& = 1000
   df& = Degrees#
   eps = 0.00000000000001
   A# = 0.5
   B# = df& / 2
   Pi# = 4 * Atn(1)
   CONCOUNT% = 0
CONLOOP:
   CONCOUNT% = CONCOUNT% + 1
   lowval = 0
   highval = 4
   If CONCOUNT% = 1 Then CONUSE# = 80
   If CONCOUNT% = 2 Then CONUSE# = 90
   If CONCOUNT% = 3 Then CONUSE# = 95
   cumprob# = CONUSE# / 200 + 0.5
   tval = lowval
   GoSub Findcumprob
   lowprob# = probval#
   tval = highval
   GoSub Findcumprob
   highprob# = probval#
   ITER& = 0
startloop:
   ITER& = ITER& + 1
   tvallast = tval
   tval = (lowval + highval) / 2
   GoSub Findcumprob
   newprob# = probval#
   If probval# < cumprob# Then
      lowval = tval
   Else
      highval = tval
   End If
   diff = Abs(tval - tvallast) - eps
   If diff <= 0 Then
      If CONCOUNT% = 1 Then
         TEMP80# = Format(tval, "0.00000000000000")
      ElseIf CONCOUNT% = 2 Then
         TEMP90# = Format(tval, "0.00000000000000")
      Else
         TEMP95# = Format(tval, "0.00000000000000")
      End If
   Else
      If ITER& < MaxIter& Then
         GoTo startloop
      Else
         MsgBox ("Program was unable to determine a t-value")
         Exit Sub
      End If
   End If
   If CONCOUNT% < 3 Then
      GoTo CONLOOP
   Else
      GoTo FindIntervals
   End If
Findcumprob:
   xval = (tval ^ 2) / (tval ^ 2 + df&)
'
'   Find C0
'
   If df& = 2 Then
      c0# = 1
      GoTo FindTerms
   End If
   If df& = 3 Then
      c0# = 4 / Pi#
      GoTo FindTerms
   End If
   If df& - 2 * (Int(df& / 2)) = 0 Then
      c0# = 1
      nterms& = df& / 2 - 1
      For I = 1 To nterms&
          TEMP# = 2 * I + 1
          c0# = (c0# * TEMP#) / (TEMP# - 1)
      Next I
      GoTo FindTerms
   Else
      c0# = 4 / Pi#
      nterms& = ((df& - 1) / 2) - 1
      For I = 1 To nterms&
          TEMP# = 2 * I + 2
          c0# = (c0# * TEMP#) / (TEMP# - 1)
      Next I
   End If
FindTerms:
   front# = (1 - xval) ^ B# * xval ^ A#
   tempval = c0#
   c(0) = c0#
   logold# = Log(c(0))
   If xval = 0 Then
      tempval = 0
      GoTo Findprobval
   End If
   For J = 1 To NumTerms
       log1# = Log((J - 1 + A# + B#) / (J + A#))
       log2# = logold#
       log3# = Log(xval)
       log4# = log1# + log2# + J * Log(xval)
       logold# = log1# + log2#
'      c(J) = ((J - 1 + A# + B#) / (J + A#)) * c(J - 1)
       tempval = tempval + Exp(log4#)
   Next J
Findprobval:
   probval# = 0.5 * (front# * tempval + 1)
   Return
FindIntervals:
   Tvalue80(Loop1%) = TEMP80#
   Tvalue90(Loop1%) = TEMP90#
   Tvalue95(Loop1%) = TEMP95#
   For Loop2% = 1 To 3
       If NONZERO&(Loop1%, Loop2%) > 0 Then
          PRCISN#(Loop1%, Loop2%, 0) = TEMP80# * STDERR#(Loop1%, Loop2%)
          PRCISN#(Loop1%, Loop2%, 1) = TEMP90# * STDERR#(Loop1%, Loop2%)
          PRCISN#(Loop1%, Loop2%, 2) = TEMP95# * STDERR#(Loop1%, Loop2%)
       End If
       VPREC80(Loop1%, Loop2%) = PRCISN#(Loop1%, Loop2%, 0) * VUNIVNBR&(Loop1%)
       VPREC90(Loop1%, Loop2%) = PRCISN#(Loop1%, Loop2%, 1) * VUNIVNBR&(Loop1%)
       VPREC95(Loop1%, Loop2%) = PRCISN#(Loop1%, Loop2%, 2) * VUNIVNBR&(Loop1%)
   Next Loop2%
'----------CALCULATE LOWER AND UPPER LIMITS-----------
   For Loop2% = 1 To 3
       If NONZERO&(Loop1%, Loop2%) > 0 Then
          temp0# = PRCISN#(Loop1%, Loop2%, 0) * VUNIVNBR&(Loop1%)
          temp1# = PRCISN#(Loop1%, Loop2%, 1) * VUNIVNBR&(Loop1%)
          temp2# = PRCISN#(Loop1%, Loop2%, 2) * VUNIVNBR&(Loop1%)
          LWRLMT#(Loop1%, Loop2%, 0) = PNTEST#(Loop1%, Loop2%) - temp0#
          LWRLMT#(Loop1%, Loop2%, 1) = PNTEST#(Loop1%, Loop2%) - temp1#
          LWRLMT#(Loop1%, Loop2%, 2) = PNTEST#(Loop1%, Loop2%) - temp2#
          UPRLMT#(Loop1%, Loop2%, 0) = PNTEST#(Loop1%, Loop2%) + temp0#
          UPRLMT#(Loop1%, Loop2%, 1) = PNTEST#(Loop1%, Loop2%) + temp1#
          UPRLMT#(Loop1%, Loop2%, 2) = PNTEST#(Loop1%, Loop2%) + temp2#
          VLWRQTY80(Loop1%, Loop2%) = LWRLMT#(Loop1%, Loop2%, 0)
          VUPRQTY80(Loop1%, Loop2%) = UPRLMT#(Loop1%, Loop2%, 0)
          VLWRQTY90(Loop1%, Loop2%) = LWRLMT#(Loop1%, Loop2%, 1)
          VUPRQTY90(Loop1%, Loop2%) = UPRLMT#(Loop1%, Loop2%, 1)
          VLWRQTY95(Loop1%, Loop2%) = LWRLMT#(Loop1%, Loop2%, 2)
          VUPRQTY95(Loop1%, Loop2%) = UPRLMT#(Loop1%, Loop2%, 2)
       End If
   Next Loop2%
'----------CALCULATE SKEWNESS-------------
   For Loop2% = 1 To 3
       If SMPLSIZE&(Loop1%) > 0 And NONZERO&(Loop1%, Loop2%) > 0 Then
          temp1# = CUBEAMT#(Loop1%, Loop2%) / SMPLSIZE&(Loop1%)
          temp1# = temp1# - (3 * (SQRAMT#(Loop1%, Loop2%) / SMPLSIZE&(Loop1%)) * MEAN#(Loop1%, Loop2%))
          temp1# = temp1# + 2 * MEAN#(Loop1%, Loop2%) ^ 3
          If SQRAMT#(Loop1%, Loop2%) / SMPLSIZE&(Loop1%) > MEAN#(Loop1%, Loop2%) ^ 2 Then
             temp2# = Sqr(SQRAMT#(Loop1%, Loop2%) / SMPLSIZE&(Loop1%) - MEAN#(Loop1%, Loop2%) ^ 2)
          Else
             temp2# = 0
          End If
          If temp2# >= 1 Then
             SKEWAMT#(Loop1%, Loop2%) = temp1# / temp2# ^ 3
          End If
       End If
       Skew#(Loop1%, Loop2%) = SKEWAMT#(Loop1%, Loop2%)
   Next Loop2%
'----------CALCULATE KURTOSIS-------------
   For Loop2% = 1 To 3
       If SMPLSIZE&(Loop1%) > 0 And NONZERO&(Loop1%, Loop2%) > 0 Then
          temp1# = QUADAMT#(Loop1%, Loop2%) / SMPLSIZE&(Loop1%)
          temp1# = temp1# - (4 * (CUBEAMT#(Loop1%, Loop2%) / SMPLSIZE&(Loop1%)) * MEAN#(Loop1%, Loop2%))
          temp1# = temp1# + (6 * (SQRAMT#(Loop1%, Loop2%) / SMPLSIZE&(Loop1%) * MEAN#(Loop1%, Loop2%) ^ 2))
          temp1# = temp1# - 3 * MEAN#(Loop1%, Loop2%) ^ 4
          If SQRAMT#(Loop1%, Loop2%) / SMPLSIZE&(Loop1%) > MEAN#(Loop1%, Loop2%) ^ 2 Then
             temp2# = Sqr(SQRAMT#(Loop1%, Loop2%) / SMPLSIZE&(Loop1%) - MEAN#(Loop1%, Loop2%) ^ 2)
          Else
             temp2# = 0
          End If
          If temp2# >= 1 Then
             KURTAMT#(Loop1%, Loop2%) = temp1# / temp2# ^ 4
          End If
       End If
       KURTOSIS#(Loop1%, Loop2%) = KURTAMT#(Loop1%, Loop2%)
   Next Loop2%
Next Loop1%
'----------CALCULATE OVERALL PRECISION----------
For Loop2% = 1 To 3
    If NONZERO&(0, Loop2%) > 0 Then
       STDERR#(0, Loop2%) = Sqr(STDERR#(0, Loop2%))
       PRCISN#(0, Loop2%, 0) = ZVAL80 * STDERR#(0, Loop2%)
       LWRLMT#(0, Loop2%, 0) = PNTEST#(0, Loop2%) - PRCISN#(0, Loop2%, 0)
       UPRLMT#(0, Loop2%, 0) = PNTEST#(0, Loop2%) + PRCISN#(0, Loop2%, 0)
       PRCISN#(0, Loop2%, 1) = ZVAL90 * STDERR#(0, Loop2%)
       LWRLMT#(0, Loop2%, 1) = PNTEST#(0, Loop2%) - PRCISN#(0, Loop2%, 1)
       UPRLMT#(0, Loop2%, 1) = PNTEST#(0, Loop2%) + PRCISN#(0, Loop2%, 1)
       PRCISN#(0, Loop2%, 2) = ZVAL95 * STDERR#(0, Loop2%)
       LWRLMT#(0, Loop2%, 2) = PNTEST#(0, Loop2%) - PRCISN#(0, Loop2%, 2)
       UPRLMT#(0, Loop2%, 2) = PNTEST#(0, Loop2%) + PRCISN#(0, Loop2%, 2)
       VSTANDARDERR(0, Loop2%) = STDERR#(0, Loop2%)
       VPROJNUMBER(0, Loop2%) = PNTEST#(0, Loop2%)
       VLWRQTY80(0, Loop2%) = LWRLMT#(0, Loop2%, 0)
       VLWRQTY90(0, Loop2%) = LWRLMT#(0, Loop2%, 1)
       VLWRQTY95(0, Loop2%) = LWRLMT#(0, Loop2%, 2)
       VUPRQTY80(0, Loop2%) = UPRLMT#(0, Loop2%, 0)
       VUPRQTY90(0, Loop2%) = UPRLMT#(0, Loop2%, 1)
       VUPRQTY95(0, Loop2%) = UPRLMT#(0, Loop2%, 2)
       VPREC80(0, Loop2%) = PRCISN#(0, Loop2%, 0)
       VPREC90(0, Loop2%) = PRCISN#(0, Loop2%, 1)
       VPREC95(0, Loop2%) = PRCISN#(0, Loop2%, 2)
    End If
Next Loop2%
Return
'***************************************************
PRINTOUT:
'***************************************************
'
'   Add new stratum sheet
'
    LinesAdd = 0
    SheetNumber = 3
    For Loop1% = 1 To STRTNBR%
       LinesAdd = 0
       If Loop1% = 1 Then
          ActiveWorkbook.Sheets("Summary").Activate
       Else
          ActiveWorkbook.Sheets("Stratum" & Str(Loop1% - 1)).Activate
       End If
       SheetNumber = SheetNumber + 1
       TableSheetName = "Stratum" & Str(Loop1%)
       AddWorksheet
       Sheets("Stratum" & Str(Loop1%)).Select
       Sheets("Stratum" & Str(Loop1%)).Move After:=Sheets(SheetNumber)
       ActiveSheet.Cells(1, 1) = "Stratum" & Str(Loop1%) & "             Population Size"
       ActiveSheet.Cells(2, 1) = "Sample Size"
       ActiveSheet.Cells(1, 2) = Format$(VUNIVNBR&(Loop1%), "###,###,###,###")
       ActiveSheet.Cells(2, 2) = Format$(SMPLSIZE&(Loop1%), "  ##,###,###")
       For Loop2% = 1 To 3
          If FFORMAT% < 4 And Loop2% > 1 Then GoTo ENDLOOP2
          If FFORMAT% < 4 And frmInput.optExam.Value = True Then ActiveSheet.Cells(4, 1) = "Summary for Examined Values"
          If FFORMAT% < 4 And frmInput.optAud.Value = True Then ActiveSheet.Cells(4, 1) = "Summary for Audited Values"
          If FFORMAT% < 4 And frmInput.optDiff.Value = True Then ActiveSheet.Cells(4, 1) = "Summary for Difference Values"
          If FFORMAT% > 3 And Loop2% = 1 Then ActiveSheet.Cells(4 + LinesAdd, 1) = "Summary for Examined Values"
          If FFORMAT% > 3 And Loop2% = 2 Then ActiveSheet.Cells(4 + LinesAdd, 1) = "Summary for Audited Values"
          If FFORMAT% > 3 And Loop2% = 3 Then ActiveSheet.Cells(4 + LinesAdd, 1) = "Summary for Difference Values"
          ActiveSheet.Cells(5 + LinesAdd, 1) = "Number of Nonzero Items"
          ActiveSheet.Cells(6 + LinesAdd, 1) = "Mean"
          ActiveSheet.Cells(7 + LinesAdd, 1) = "Standard Deviation"
          ActiveSheet.Cells(8 + LinesAdd, 1) = "Skewness"
          ActiveSheet.Cells(9 + LinesAdd, 1) = "Standard Error (Mean)"
          ActiveSheet.Cells(10 + LinesAdd, 1) = "Standard Error (Total)"
          ActiveSheet.Cells(11 + LinesAdd, 1) = "Point Estimate"
          ActiveSheet.Cells(5 + LinesAdd, 6) = "Confidence Level"
          ActiveSheet.Cells(6 + LinesAdd, 5) = "80" & "%"
          ActiveSheet.Cells(6 + LinesAdd, 6) = "90" & "%"
          ActiveSheet.Cells(6 + LinesAdd, 7) = "95" & "%"
          ActiveSheet.Cells(7 + LinesAdd, 4) = "Lower Limit"
          ActiveSheet.Cells(8 + LinesAdd, 4) = "Upper Limit"
          ActiveSheet.Cells(9 + LinesAdd, 4) = "Precision Amount"
          ActiveSheet.Cells(10 + LinesAdd, 4) = "Precision Percent"
          ActiveSheet.Cells(11 + LinesAdd, 4) = "t-Value Used"
          ActiveSheet.Cells(5 + LinesAdd, 2) = Format$(NONZERO&(Loop1%, Loop2%), "###,###,###,###")
          ActiveSheet.Cells(6 + LinesAdd, 2) = Format$(MEAN#(Loop1%, Loop2%), "###,###,###.00")
          ActiveSheet.Cells(7 + LinesAdd, 2) = Format$(STDDEV#(Loop1%, Loop2%), "###,###,###.00")
          ActiveSheet.Cells(8 + LinesAdd, 2) = Format$(SKEWAMT#(Loop1%, Loop2%), "###,###,###.00")
          ActiveSheet.Cells(9 + LinesAdd, 2) = Format$(STDERR#(Loop1%, Loop2%), "###,###,###.00")
          ActiveSheet.Cells(10 + LinesAdd, 2) = Format$(VUNIVNBR&(Loop1%) * STDERR#(Loop1%, Loop2%), "###,###,###,###")
          ActiveSheet.Cells(11 + LinesAdd, 2) = Format$(PNTEST#(Loop1%, Loop2%), "###,###,###,###")
          ActiveSheet.Cells(7 + LinesAdd, 5) = Format$(LWRLMT#(Loop1%, Loop2%, 0), "###,###,###,###")
          ActiveSheet.Cells(8 + LinesAdd, 5) = Format$(UPRLMT#(Loop1%, Loop2%, 0), "###,###,###,###")
          temp1# = PRCISN#(Loop1%, Loop2%, 0) * VUNIVNBR&(Loop1%)
          ActiveSheet.Cells(9 + LinesAdd, 5) = Format$(temp1#, "###,###,###,###")
          temp1# = 0
          If MEAN#(Loop1%, Loop2%) > 0 Then
             temp1# = PRCISN#(Loop1%, Loop2%, 0) / MEAN#(Loop1%, Loop2%)
          End If
          ActiveSheet.Cells(10 + LinesAdd, 5) = Format$(temp1#, "###,###,###,###.00%")
          ActiveSheet.Cells(11 + LinesAdd, 5) = Format$(Tvalue80(Loop1%), "#.000000000000")
          ActiveSheet.Cells(7 + LinesAdd, 6) = Format$(LWRLMT#(Loop1%, Loop2%, 1), "###,###,###,###")
          ActiveSheet.Cells(8 + LinesAdd, 6) = Format$(UPRLMT#(Loop1%, Loop2%, 1), "###,###,###,###")
          temp1# = PRCISN#(Loop1%, Loop2%, 1) * VUNIVNBR&(Loop1%)
          ActiveSheet.Cells(9 + LinesAdd, 6) = Format$(temp1#, "###,###,###,###")
          temp1# = 0
          If MEAN#(Loop1%, Loop2%) > 0 Then
             temp1# = PRCISN#(Loop1%, Loop2%, 1) / MEAN#(Loop1%, Loop2%)
          End If
          ActiveSheet.Cells(10 + LinesAdd, 6) = Format$(temp1#, "###,###,###,###.00%")
          ActiveSheet.Cells(11 + LinesAdd, 6) = Format$(Tvalue90(Loop1%), "#.000000000000")
          ActiveSheet.Cells(7 + LinesAdd, 7) = Format$(LWRLMT#(Loop1%, Loop2%, 2), "###,###,###,###")
          ActiveSheet.Cells(8 + LinesAdd, 7) = Format$(UPRLMT#(Loop1%, Loop2%, 2), "###,###,###,###")
          temp1# = PRCISN#(Loop1%, Loop2%, 2) * VUNIVNBR&(Loop1%)
          ActiveSheet.Cells(9 + LinesAdd, 7) = Format$(temp1#, "###,###,###,###")
          temp1# = 0
          If MEAN#(Loop1%, Loop2%) > 0 Then
             temp1# = PRCISN#(Loop1%, Loop2%, 2) / MEAN#(Loop1%, Loop2%)
          End If
          ActiveSheet.Cells(10 + LinesAdd, 7) = Format$(temp1#, "###,###,###,###.00%")
          ActiveSheet.Cells(11 + LinesAdd, 7) = Format$(Tvalue95(Loop1%), "#.000000000000")
          ActiveSheet.Range("A2").Select
          Selection.ColumnWidth = 34.5
          ActiveSheet.Range("B2").Select
          Selection.ColumnWidth = 13.3
          ActiveSheet.Range("C2").Select
          Selection.ColumnWidth = 3.6
          ActiveSheet.Range("D2").Select
          Selection.ColumnWidth = 20.45
          ActiveSheet.Range("E2:G2").Select
          Selection.ColumnWidth = 14.5
          ActiveSheet.Columns("A:A").Select
          With Selection.Font
               .Name = "Arial"
               .Size = 12
               .Bold = True
          End With
          With Selection
               .HorizontalAlignment = xlRight
               .VerticalAlignment = xlBottom
          End With
          ActiveSheet.Columns("B:B").Select
          With Selection.Font
               .Name = "Arial"
               .Size = 12
          End With
          With Selection
               .HorizontalAlignment = xlRight
               .VerticalAlignment = xlBottom
          End With
          ActiveSheet.Columns("D:D").Select
          With Selection.Font
               .Name = "Arial"
               .Size = 12
               .Bold = True
          End With
          With Selection
               .HorizontalAlignment = xlRight
               .VerticalAlignment = xlBottom
          End With
          ActiveSheet.Range(ActiveSheet.Cells(6 + LinesAdd, 5), ActiveSheet.Cells(6 + LinesAdd, 7)).Select
          With Selection.Font
               .Name = "Arial"
               .Size = 12
               .Bold = True
          End With
          With Selection
               .HorizontalAlignment = xlCenter
               .VerticalAlignment = xlBottom
          End With
          ActiveSheet.Range(ActiveSheet.Cells(7 + LinesAdd, 5), ActiveSheet.Cells(10 + LinesAdd, 7)).Select
          With Selection.Font
               .Name = "Arial"
               .Size = 12
               .Bold = False
          End With
          With Selection
               .HorizontalAlignment = xlCenter
               .VerticalAlignment = xlBottom
          End With
          ActiveSheet.Range(ActiveSheet.Cells(11 + LinesAdd, 5), ActiveSheet.Cells(11 + LinesAdd, 7)).Select
          Selection.NumberFormat = "0.000000000000"
          With Selection.Font
               .Name = "Arial"
               .Size = 10
               .Bold = False
          End With
          With Selection
               .HorizontalAlignment = xlCenter
               .VerticalAlignment = xlBottom
          End With
          ActiveSheet.Range(ActiveSheet.Cells(5 + LinesAdd, 6), ActiveSheet.Cells(5 + LinesAdd, 6)).Select
          With Selection.Font
               .Name = "Arial"
               .Size = 12
               .Bold = True
          End With
          With Selection
               .HorizontalAlignment = xlLeft
               .VerticalAlignment = xlBottom
          End With
          ActiveSheet.Range(ActiveSheet.Cells(6 + LinesAdd, 2), ActiveSheet.Cells(6 + LinesAdd, 2)).Select
          Selection.NumberFormat = "0.00"
          ActiveSheet.Range(ActiveSheet.Cells(7 + LinesAdd, 2), ActiveSheet.Cells(7 + LinesAdd, 2)).Select
          Selection.NumberFormat = "0.00"
          ActiveSheet.Range(ActiveSheet.Cells(8 + LinesAdd, 2), ActiveSheet.Cells(8 + LinesAdd, 2)).Select
          Selection.NumberFormat = "0.00"
          ActiveSheet.Range(ActiveSheet.Cells(9 + LinesAdd, 2), ActiveSheet.Cells(9 + LinesAdd, 2)).Select
          Selection.NumberFormat = "0.00"
          With ActiveSheet.PageSetup
               .Orientation = xlLandscape
          End With
          If FFORMAT% < 4 Then ActiveSheet.Cells(11 + LinesAdd, 2).Select
          If FFORMAT% > 3 Then ActiveSheet.Cells(1, 1).Select
          If FFORMAT% > 3 Then
             LinesAdd = LinesAdd + 9
          Else
             LinesAdd = 0
          End If
       Next Loop2%
ENDLOOP2:
    Next Loop1%
PRINTSUMMARYONLY:
     LinesAdd = 0
     For Loop2% = 1 To 3
          If FFORMAT% < 4 And Loop2% > 1 Then GoTo ENDLOOP22
          If STRTNBR% = 1 Then GoTo ENDLOOP22
          ActiveWorkbook.Sheets("Summary").Activate
          ActiveSheet.Cells(1, 1) = "Overall" & "                 Population Size"
          ActiveSheet.Cells(2, 1) = "Sample Size"
          ActiveSheet.Cells(1, 2) = Format$(VUNIVNBR&(0), "###,###,###,###")
          ActiveSheet.Cells(2, 2) = Format$(SMPLSIZE&(0), "  ##,###,###")
          If FFORMAT% < 4 And frmInput.optExam.Value = True Then ActiveSheet.Cells(4 + LinesAdd, 1) = "Summary for Examined Values"
          If FFORMAT% < 4 And frmInput.optAud.Value = True Then ActiveSheet.Cells(4 + LinesAdd, 1) = "Summary for Audited Values"
          If FFORMAT% < 4 And frmInput.optDiff.Value = True Then ActiveSheet.Cells(4 + LinesAdd, 1) = "Summary for Difference Values"
          If FFORMAT% > 3 And Loop2% = 1 Then ActiveSheet.Cells(4 + LinesAdd, 1) = "Summary for Examined Values"
          If FFORMAT% > 3 And Loop2% = 2 Then ActiveSheet.Cells(4 + LinesAdd, 1) = "Summary for Audited Values"
          If FFORMAT% > 3 And Loop2% = 3 Then ActiveSheet.Cells(4 + LinesAdd, 1) = "Summary for Difference Values"
          ActiveSheet.Cells(5 + LinesAdd, 1) = "Number of Nonzero Items"
          ActiveSheet.Cells(6 + LinesAdd, 1) = "Standard Error (Mean)"
          ActiveSheet.Cells(7 + LinesAdd, 1) = "Standard Error (Total)"
          ActiveSheet.Cells(8 + LinesAdd, 1) = "Point Estimate"
          ActiveSheet.Cells(5 + LinesAdd, 2) = NONZERO&(0, Loop2%)
          ActiveSheet.Cells(8 + LinesAdd, 2) = Format$(PNTEST#(0, Loop2%), "###,###,###,###")
          ActiveSheet.Cells(7 + LinesAdd, 2) = Format$(STDERR#(0, Loop2%), "###,###,###,###")
          ActiveSheet.Cells(6 + LinesAdd, 2) = Format$(STDERR#(0, Loop2%) / VUNIVNBR&(0), "###,###,###,###.00")
          ActiveSheet.Cells(2 + LinesAdd, 6) = "Confidence Level"
          ActiveSheet.Cells(3 + LinesAdd, 5) = "80" & "%"
          ActiveSheet.Cells(3 + LinesAdd, 6) = "90" & "%"
          ActiveSheet.Cells(3 + LinesAdd, 7) = "95" & "%"
          ActiveSheet.Cells(4 + LinesAdd, 4) = "Lower Limit"
          ActiveSheet.Cells(5 + LinesAdd, 4) = "Upper Limit"
          ActiveSheet.Cells(6 + LinesAdd, 4) = "Precision Amount"
          ActiveSheet.Cells(7 + LinesAdd, 4) = "Precision Percent"
          ActiveSheet.Cells(8 + LinesAdd, 4) = "Z-Value Used"
          ActiveSheet.Cells(4 + LinesAdd, 5) = Format$(LWRLMT#(0, Loop2%, 0), "###,###,###,###")
          ActiveSheet.Cells(5 + LinesAdd, 5) = Format$(UPRLMT#(0, Loop2%, 0), "###,###,###,###")
          ActiveSheet.Cells(6 + LinesAdd, 5) = Format$(PRCISN#(0, Loop2%, 0), "###,###,###,###")
          temp1# = 0
          If PNTEST#(0, Loop2%) > 0 Then
             temp1# = PRCISN#(0, Loop2%, 0) / PNTEST#(0, Loop2%)
          End If
          ActiveSheet.Cells(7 + LinesAdd, 5) = Format$(temp1#, "###,###,###,###.00%")
          ActiveSheet.Cells(8 + LinesAdd, 5) = Format$(ZVAL80, "#.000000000000")
          ActiveSheet.Cells(4 + LinesAdd, 6) = Format$(LWRLMT#(0, Loop2%, 1), "###,###,###,###")
          ActiveSheet.Cells(5 + LinesAdd, 6) = Format$(UPRLMT#(0, Loop2%, 1), "###,###,###,###")
          ActiveSheet.Cells(6 + LinesAdd, 6) = Format$(PRCISN#(0, Loop2%, 1), "###,###,###,###")
          temp1# = 0
          If PNTEST#(0, Loop2%) > 0 Then
             temp1# = PRCISN#(0, Loop2%, 1) / PNTEST#(0, Loop2%)
          End If
          ActiveSheet.Cells(7 + LinesAdd, 6) = Format$(temp1#, "###,###,###,###.00%")
          ActiveSheet.Cells(8 + LinesAdd, 6) = Format$(ZVAL90, "#.000000000000")
          ActiveSheet.Cells(4 + LinesAdd, 7) = Format$(LWRLMT#(0, Loop2%, 2), "###,###,###,###")
          ActiveSheet.Cells(5 + LinesAdd, 7) = Format$(UPRLMT#(0, Loop2%, 2), "###,###,###,###")
          ActiveSheet.Cells(6 + LinesAdd, 7) = Format$(PRCISN#(0, Loop2%, 2), "###,###,###,###")
          temp1# = 0
          If PNTEST#(0, Loop2%) > 0 Then
             temp1# = PRCISN#(0, Loop2%, 2) / PNTEST#(0, Loop2%)
          End If
          ActiveSheet.Cells(7 + LinesAdd, 7) = Format$(temp1#, "###,###,###,###.00%")
          ActiveSheet.Cells(8 + LinesAdd, 7) = Format$(ZVAL95, "#.000000000000")
          ActiveSheet.Range(ActiveSheet.Cells(6 + LinesAdd, 2), ActiveSheet.Cells(6 + LinesAdd, 2)).Select
          Selection.NumberFormat = "0.00"
          ActiveSheet.Columns("A:A").Select
          With Selection.Font
               .Name = "Arial"
               .Size = 12
               .Bold = True
          End With
          With Selection
               .HorizontalAlignment = xlRight
               .VerticalAlignment = xlBottom
          End With
          ActiveSheet.Columns("B:B").Select
          With Selection.Font
               .Name = "Arial"
               .Size = 12
          End With
          With Selection
               .HorizontalAlignment = xlRight
               .VerticalAlignment = xlBottom
          End With
          ActiveSheet.Columns("D:D").Select
          With Selection.Font
               .Name = "Arial"
               .Size = 12
               .Bold = True
          End With
          With Selection
               .HorizontalAlignment = xlRight
               .VerticalAlignment = xlBottom
          End With
          ActiveSheet.Range(ActiveSheet.Cells(3 + LinesAdd, 5), ActiveSheet.Cells(3 + LinesAdd, 7)).Select
          With Selection.Font
               .Name = "Arial"
               .Size = 12
               .Bold = True
          End With
          With Selection
               .HorizontalAlignment = xlCenter
               .VerticalAlignment = xlBottom
          End With
          ActiveSheet.Range(ActiveSheet.Cells(4 + LinesAdd, 5), ActiveSheet.Cells(7 + LinesAdd, 7)).Select
          With Selection.Font
               .Name = "Arial"
               .Size = 12
               .Bold = False
          End With
          With Selection
               .HorizontalAlignment = xlCenter
               .VerticalAlignment = xlBottom
          End With
          ActiveSheet.Range(ActiveSheet.Cells(8 + LinesAdd, 5), ActiveSheet.Cells(8 + LinesAdd, 7)).Select
          Selection.NumberFormat = "0.000000000000"
          With Selection.Font
               .Name = "Arial"
               .Size = 10
               .Bold = False
          End With
          With Selection
               .HorizontalAlignment = xlCenter
               .VerticalAlignment = xlBottom
          End With
          ActiveSheet.Range(ActiveSheet.Cells(2 + LinesAdd, 6), ActiveSheet.Cells(2 + LinesAdd, 6)).Select
          With Selection.Font
               .Name = "Arial"
               .Size = 12
               .Bold = True
          End With
          With Selection
               .HorizontalAlignment = xlLeft
               .VerticalAlignment = xlBottom
          End With
          ActiveSheet.Range(ActiveSheet.Cells(6 + LinesAdd, 2), ActiveSheet.Cells(6 + LinesAdd, 2)).Select
          Selection.NumberFormat = "0.00"
          With ActiveSheet.PageSetup
               .Orientation = xlLandscape
          End With
          If FFORMAT% < 4 Then
             ActiveSheet.Cells(8 + LinesAdd, 2).Select
          Else
             ActiveSheet.Cells(1, 1).Select
          End If
ENDLOOP22:
    LinesAdd = LinesAdd + 9
    Next Loop2%
    Return
End Sub
