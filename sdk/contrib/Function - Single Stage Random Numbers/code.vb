


Private Sub cmdFileNames_Click() '945C50
  Dim var_54 As Variant
  Dim var_1C As CommonDialog
loc_00945CAC:   var_18 = vbNullString
loc_00945D0D:   var_58 = frmTwoStage.chkDisk.Value
loc_00945D3B:   setz al
loc_00945D52:   If var_5C = 0 Then GoTo loc_00945EC7
  loc_00945D5E: 00EE0174h = 00EE0174h + 0001h
loc_00945D7C:   If var_54 >= 11 Then GoTo loc_00945D84
loc_00945D82:   GoTo loc_00945D8C
loc_00945D84:   'Referenced from: 00945D7C
loc_00945D84:   var_eax = Err.Raise
loc_00945D89:   var_70 = Err.Raise
loc_00945D8C:   'Referenced from: 00945D82
loc_00945D9B:   var_34 = "Text Files (*.txt)|*.txt|All files (*.*)|*.*"
  loc_00945DD5: var_1C = var_1C._Action
  loc_00945E1C: var_1C = var_1C._Action
  loc_00945E46: var_1C = var_1C._Action
  loc_00945E77: var_2C = var_1C._Action
  loc_00945EA7: var_eax = call Proc_70_0_CDDE6D(var_2C, var_2C, var_38)
loc_00945EBA:   var_18 = var_2C
loc_00945EC7:   'Referenced from: 00945D52
loc_00945F23:   var_58 = frmTwoStage.chkAccess.Value
loc_00945F51:   setz al
loc_00945F68:   If var_5C = 0 Then GoTo loc_00946106
  loc_00945F74: 00EE0174h = 00EE0174h + 0001h
loc_00945F92:   If var_54 >= 11 Then GoTo loc_00945F9A
loc_00945F98:   GoTo loc_00945FA2
loc_00945F9A:   'Referenced from: 00945F92
loc_00945F9A:   var_eax = Err.Raise
loc_00945F9F:   var_7C = Err.Raise
loc_00945FA2:   'Referenced from: 00945F98
loc_00945FB1:   var_34 = "Access File |*.mdb;*.accdb"
  loc_00945FEB: var_1C = var_1C._Action
loc_00946002:   If Len(var_18) <= 0 Then GoTo loc_0094605C
loc_00946011:   var_24 = var_18 & ".accdb"
  loc_00946047: var_1C = var_1C._Action
loc_0094605C:   'Referenced from: 00946002
  loc_00946079: var_1C = var_1C._Action
loc_00946093:   If Len(var_18) <> 0 Then GoTo loc_00946106
  loc_009460B6: var_2C = var_1C._Action
  loc_009460E6: var_eax = call Proc_70_0_CDDE6D(var_2C, var_2C, var_28)
loc_009460F9:   var_18 = var_2C
loc_00946106:   'Referenced from: 00945F68
loc_00946162:   var_58 = frmTwoStage.chkExcel.Value
loc_00946196:   setz al
loc_009461AD:   If var_5C = 0 Then GoTo loc_00946351
  loc_009461B9: 00EE0174h = 00EE0174h + 0001h
loc_009461D7:   If var_54 >= 11 Then GoTo loc_009461E2
loc_009461E0:   GoTo loc_009461ED
loc_009461E2:   'Referenced from: 009461D7
loc_009461E2:   var_eax = Err.Raise
loc_009461E7:   var_88 = Err.Raise
loc_009461ED:   'Referenced from: 009461E0
loc_009461FC:   var_34 = "Excel File|*.xls;*.xlsx"
  loc_00946236: var_1C = var_1C._Action
loc_0094624D:   If Len(var_18) <= 0 Then GoTo loc_009462A7
loc_0094625C:   var_24 = var_18 & ".xlsx"
  loc_00946292: var_1C = var_1C._Action
loc_009462A7:   'Referenced from: 0094624D
  loc_009462C4: var_1C = var_1C._Action
loc_009462DE:   If Len(var_18) <> 0 Then GoTo loc_00946351
  loc_00946301: var_2C = var_1C._Action
  loc_00946331: var_eax = call Proc_70_0_CDDE6D(var_2C, var_2C, var_28)
loc_00946344:   var_18 = var_2C
loc_00946351:   'Referenced from: 009461AD
loc_009463B9:   var_58 = frmTwoStage.chkFlat.Value
loc_009463ED:   setz al
loc_00946404:   If var_5C = 0 Then GoTo loc_00946519
  loc_00946410: 00EE0174h = 00EE0174h + 0001h
loc_0094642E:   If var_54 >= 11 Then GoTo loc_00946439
loc_00946437:   GoTo loc_00946444
loc_00946439:   'Referenced from: 0094642E
loc_00946439:   var_eax = Err.Raise
loc_0094643E:   var_94 = Err.Raise
loc_00946444:   'Referenced from: 00946437
loc_0094645D:   If Len(var_18) <= 0 Then GoTo loc_009464A5
loc_00946462:   var_34 = var_18
  loc_00946498: var_1C = var_1C._Action
loc_009464A5:   'Referenced from: 0094645D
  loc_009464DF: var_1C = var_1C._Action
  loc_00946509: var_1C = var_1C._Action
loc_00946519:   'Referenced from: 00946404
  loc_00946547: var_eax = Unknown_VTable_Call[eax+0000009Ch]
  loc_0094654F: var_58 = Unknown_VTable_Call[eax+0000009Ch]
loc_009465A9:   frmTwoStage.Command3.Visible = True
loc_009465B1:   var_58 = eax
  loc_0094660B: var_eax = Unknown_VTable_Call[eax+0000009Ch]
  loc_00946613: var_58 = Unknown_VTable_Call[eax+0000009Ch]
loc_0094666D:   frmTwoStage.cmdFileNames.Visible = False
loc_00946675:   var_58 = eax
loc_009466B6:   GoTo loc_009466C9
loc_009466C8:   Exit Sub
loc_009466C9:   'Referenced from: 009466B6
End Sub

Private Sub txtauditname_KeyPress(KeyAscii As Integer) '9496F7
loc_00949770:   var_24 = txtauditname.Text
loc_009497A4:   setg cl
loc_009497C3:   If var_28 = 0 Then GoTo loc_009497CC
loc_009497CC:   'Referenced from: 009497C3
loc_009497D8:   GoTo loc_009497EB
loc_009497EA:   Exit Sub
loc_009497EB:   'Referenced from: 009497D8
End Sub

Private Sub optyes_Click() '948E5C
  loc_00948ECB: var_eax = Unknown_VTable_Call[eax+0000009Ch]
  loc_00948ED3: var_20 = Unknown_VTable_Call[eax+0000009Ch]
loc_00948F27:   txtseed.Visible = True
loc_00948F2F:   var_20 = eax
loc_00948F81:   var_eax = txtseed.SetFocus
loc_00948F89:   var_20 = txtseed.SetFocus
loc_00948FC4:   GoTo loc_00948FCF
loc_00948FCE:   Exit Sub
loc_00948FCF:   'Referenced from: 00948FC4
End Sub

Private Sub txtspares_Change() '94C221
  Dim var_C8 As TextBox
loc_0094C2A5:   var_C4 = txtspares.Text
loc_0094C2EA:   setg cl
loc_0094C30F:   If var_C8 = 0 Then GoTo loc_0094C3BE
loc_0094C345:   var_30 = txtspares.Text
loc_0094C34D:   var_C4 = var_30
loc_0094C3A7:   var_24 = var_30
loc_0094C3BC:   GoTo loc_0094C3DD
loc_0094C3BE:   'Referenced from: 0094C30F
loc_0094C3D8:   var_24 = False
loc_0094C3DD:   'Referenced from: 0094C3BC
loc_0094C40D:   var_30 = txtseqorder.Text
loc_0094C415:   var_C4 = var_30
loc_0094C473:   var_DC = var_30
loc_0094C483:   var_44 = var_DC
loc_0094C4B0:   var_28 = Format(var_DC, "#####0")
loc_0094C503:   var_30 = txtspares.Text
loc_0094C50B:   var_C4 = var_30
loc_0094C569:   var_E0 = var_30
loc_0094C579:   var_44 = var_E0
loc_0094C5A6:   var_2C = Format(var_E0, "#####0")
loc_0094C601:   var_C4 = txtseqorder.Text
loc_0094C672:   var_CC = txtspares.Text
loc_0094C6B7:   setg bl
loc_0094C6C8:   setg cl
loc_0094C704:   If var_D0 = 0 Then GoTo loc_0094C92A
  loc_0094C735: fcomp real8 ptr [00402908h]
loc_0094C73D:   sahf
loc_0094C73E:   If Err.Number <= 0 Then GoTo loc_0094C92A
loc_0094C78B:   var_4C = "The maximum number of values is 10,000.  Re-enter both values."
loc_0094C7F2:   txtseqorder.Text = vbNullString
loc_0094C7FA:   var_C4 = eax
loc_0094C86C:   txtspares.Text = vbNullString
loc_0094C874:   var_C4 = eax
loc_0094C8E1:   var_eax = txtseqorder.SetFocus
loc_0094C8E9:   var_C4 = txtseqorder.SetFocus
loc_0094C937:   GoTo loc_0094C978
loc_0094C977:   Exit Sub
loc_0094C978:   'Referenced from: 0094C937
End Sub

Private Sub txtspares_KeyPress(KeyAscii As Integer) '94C9B5
  loc_0094CA06: var_eax = call Proc_CDDE13(eax, edi, esi)
  loc_0094CA10: If call Proc_CDDE13(eax, edi, esi) <> 0 Then GoTo loc_0094CA19
loc_0094CA19:   'Referenced from: 0094CA10
loc_0094CA3B:   leaved
End Sub

Private Sub txtspares_LostFocus() '94CA3F
  Dim var_60 As TextBox
loc_0094CAB8:   var_64 = txtspares.Text
loc_0094CAEB:   setg cl
loc_0094CB0A:   If var_68 = 0 Then GoTo loc_0094CC43
loc_0094CB28:   var_60 = var_2C
loc_0094CB37:   var_28 = txtspares.Text
loc_0094CB3F:   var_64 = var_28
loc_0094CBF2:   txtspares.Text = CStr(Format(var_28, "###,##0"))
loc_0094CBFA:   var_64 = eax
loc_0094CC43:   'Referenced from: 0094CB0A
loc_0094CC50:   GoTo loc_0094CC75
loc_0094CC74:   Exit Sub
loc_0094CC75:   'Referenced from: 0094CC50
End Sub

Private Sub txtlow_KeyPress(KeyAscii As Integer) '94B10F
  loc_0094B160: var_eax = call Proc_CDDE13(eax, edi, esi)
  loc_0094B16A: If call Proc_CDDE13(eax, edi, esi) <> 0 Then GoTo loc_0094B173
loc_0094B173:   'Referenced from: 0094B16A
loc_0094B195:   leaved
End Sub

Private Sub txtlow_LostFocus() '94B199
  Dim var_60 As TextBox
loc_0094B212:   var_64 = txtlow.Text
loc_0094B245:   setg cl
loc_0094B264:   If var_68 = 0 Then GoTo loc_0094B39D
loc_0094B282:   var_60 = var_2C
loc_0094B291:   var_28 = txtlow.Text
loc_0094B299:   var_64 = var_28
loc_0094B34C:   txtlow.Text = CStr(Format(var_28, "###,##0"))
loc_0094B354:   var_64 = eax
loc_0094B39D:   'Referenced from: 0094B264
loc_0094B3AA:   GoTo loc_0094B3CF
loc_0094B3CE:   Exit Sub
loc_0094B3CF:   'Referenced from: 0094B3AA
End Sub

Private Sub txtseqorder_KeyPress(KeyAscii As Integer) '94BCAB
  loc_0094BCFC: var_eax = call Proc_CDDE13(eax, edi, esi)
  loc_0094BD06: If call Proc_CDDE13(eax, edi, esi) <> 0 Then GoTo loc_0094BD0F
loc_0094BD0F:   'Referenced from: 0094BD06
loc_0094BD31:   leaved
End Sub

Private Sub txtseqorder_LostFocus() '94BD35
  Dim var_B0 As TextBox
loc_0094BDB9:   var_B4 = txtseqorder.Text
loc_0094BDFE:   setg cl
loc_0094BE23:   If var_B8 = 0 Then GoTo loc_0094C1BF
loc_0094BE61:   var_B4 = txtseqorder.Text
  loc_0094BEA2: fcomp real8 ptr [004013A0h]
loc_0094BEAA:   sahf
loc_0094BEAB:   If var_C8 <> 0 Then GoTo loc_0094BEB9
loc_0094BEB7:   GoTo loc_0094BEC0
loc_0094BEB9:   'Referenced from: 0094BEAB
loc_0094BEC0:   'Referenced from: 0094BEB7
loc_0094BEC8:   var_B8 = var_CC
loc_0094BEE8:   If var_B8 = 0 Then GoTo loc_0094C056
loc_0094BF2C:   var_3C = "The number of generated random numbers must be positive."
loc_0094BF93:   txtseqorder.Text = vbNullString
loc_0094BF9B:   var_B4 = eax
loc_0094C008:   var_eax = txtseqorder.SetFocus
loc_0094C010:   var_B4 = txtseqorder.SetFocus
loc_0094C051:   GoTo loc_0094C1BF
loc_0094C056:   'Referenced from: 0094BEE8
loc_0094C06E:   var_B0 = var_2C
loc_0094C086:   var_28 = txtseqorder.Text
loc_0094C08E:   var_B4 = var_28
loc_0094C15C:   txtseqorder.Text = CStr(Format(var_28, "###,###"))
loc_0094C164:   var_B4 = eax
loc_0094C1BF:   'Referenced from: 0094BE23
loc_0094C1CC:   GoTo loc_0094C1F9
loc_0094C1F8:   Exit Sub
loc_0094C1F9:   'Referenced from: 0094C1CC
End Sub

Private Sub txtlow2_KeyPress(KeyAscii As Integer) '94B3F7
  loc_0094B448: var_eax = call Proc_CDDE13(eax, edi, esi)
  loc_0094B452: If call Proc_CDDE13(eax, edi, esi) <> 0 Then GoTo loc_0094B45B
loc_0094B45B:   'Referenced from: 0094B452
loc_0094B47D:   leaved
End Sub

Private Sub txtlow2_LostFocus() '94B481
  Dim var_60 As TextBox
loc_0094B4FA:   var_64 = txtlow2.Text
loc_0094B52D:   setg cl
loc_0094B54C:   If var_68 = 0 Then GoTo loc_0094B685
loc_0094B56A:   var_60 = var_2C
loc_0094B579:   var_28 = txtlow2.Text
loc_0094B581:   var_64 = var_28
loc_0094B634:   txtlow2.Text = CStr(Format(var_28, "###,##0"))
loc_0094B63C:   var_64 = eax
loc_0094B685:   'Referenced from: 0094B54C
loc_0094B692:   GoTo loc_0094B6B7
loc_0094B6B6:   Exit Sub
loc_0094B6B7:   'Referenced from: 0094B692
End Sub

Private Sub Command1_Click() '946894
loc_009468DE:   End
loc_00946905:   leaved
End Sub

Private Sub Command2_Click() '946CD3
loc_00946D59:   frmTwoStage.Visible = False
loc_00946D61:   var_40 = eax
loc_00946DC2:   frmFileNames.Visible = False
loc_00946DCA:   var_40 = eax
loc_00946E46:   frmFileNames.Text1.Text = vbNullString
loc_00946E4E:   var_40 = eax
loc_00946ED2:   frmFileNames.Text2.Text = vbNullString
loc_00946EDA:   var_40 = eax
loc_00946F5E:   frmFileNames.Text3.Text = vbNullString
loc_00946F66:   var_40 = eax
loc_00946FEA:   frmFileNames.Text4.Text = vbNullString
loc_00946FF2:   var_40 = eax
loc_00947076:   frmFileNames.Text5.Text = vbNullString
loc_0094707E:   var_40 = eax
loc_0094710E:   frmFileNames.Text6.Text = vbNullString
loc_00947116:   var_40 = eax
loc_0094718C:   var_eax = frmTwoStage.Hide
loc_00947194:   var_40 = frmTwoStage.Hide
  loc_00947240: var_eax = frmRATSTATS.Show var_28, var_24
  loc_00947248: var_40 = frmRATSTATS.Show var_28, var_24
  loc_0094727D: var_eax = Unknown_VTable_Call[eax+00000350h]
loc_0094729A:   frmRATSTATS.CurrentX = NAN
loc_009472A2:   var_40 = eax
  loc_009472DF: var_eax = Unknown_VTable_Call[eax+00000344h]
loc_009472FF:   frmRATSTATS.MousePointer = vbNullString
loc_00947307:   var_40 = eax
  loc_00947344: var_eax = Unknown_VTable_Call[eax+00000340h]
loc_00947364:   frmRATSTATS.MousePointer = vbNullString
loc_0094736C:   var_40 = eax
  loc_009473A9: var_eax = Unknown_VTable_Call[eax+0000033Ch]
loc_009473C9:   frmRATSTATS.MousePointer = vbNullString
loc_009473D1:   var_40 = eax
  loc_0094740E: var_eax = Unknown_VTable_Call[eax+00000318h]
loc_0094742E:   frmRATSTATS.MousePointer = vbNullString
loc_00947436:   var_40 = eax
  loc_00947473: var_eax = Unknown_VTable_Call[eax+00000314h]
loc_00947493:   frmRATSTATS.MousePointer = vbNullString
loc_0094749B:   var_40 = eax
  loc_009474D8: var_eax = Unknown_VTable_Call[eax+00000310h]
loc_009474F8:   frmRATSTATS.MousePointer = vbNullString
loc_00947500:   var_40 = eax
  loc_0094753D: var_eax = Unknown_VTable_Call[eax+0000030Ch]
loc_0094755D:   frmRATSTATS.MousePointer = vbNullString
loc_00947565:   var_40 = eax
  loc_009475A2: var_eax = Unknown_VTable_Call[eax+00000330h]
loc_009475BF:   frmRATSTATS.CurrentX = 0
loc_009475C7:   var_40 = eax
  loc_00947604: var_eax = Unknown_VTable_Call[eax+0000032Ch]
loc_00947621:   frmRATSTATS.CurrentX = 0
loc_00947629:   var_40 = eax
  loc_00947666: var_eax = Unknown_VTable_Call[eax+00000328h]
loc_00947683:   frmRATSTATS.CurrentX = 0
loc_0094768B:   var_40 = eax
  loc_009476C8: var_eax = Unknown_VTable_Call[eax+00000324h]
loc_009476E5:   frmRATSTATS.CurrentX = 0
loc_009476ED:   var_40 = eax
  loc_0094772A: var_eax = Unknown_VTable_Call[eax+00000320h]
loc_00947747:   frmRATSTATS.CurrentX = 0
loc_0094774F:   var_40 = eax
loc_00947798:   GoTo loc_009477A3
loc_009477A2:   Exit Sub
loc_009477A3:   'Referenced from: 00947798
End Sub

Private Sub chkDisk_Click() '92DDE0
loc_0092DE51:   var_24 = chkDisk.Value
loc_0092DE59:   var_30 = var_24
loc_0092DEA7:   var_28 = chkAccess.Value
loc_0092DEAF:   var_38 = var_28
  loc_0092DEDA: 0001h = 0001h - var_24
  loc_0092DEE8: 0001h = 0001h - var_28
  loc_0092DEF2: 0001h = 0001h *
loc_0092DF39:   var_24 = chkExcel.Value
loc_0092DF41:   var_30 = var_24
loc_0092DF8F:   var_28 = chkFlat.Value
loc_0092DF97:   var_38 = var_28
  loc_0092DFC2: 0001h = 0001h - var_24
  loc_0092DFD0: var_18 = var_18 * 0001h
  loc_0092DFDE: 0001h = 0001h - var_28
  loc_0092DFE8: var_18 = var_18 * 0001h
loc_0092DFF2:   var_18 = var_18
loc_0092E00E:   If var_18 <> 0 Then GoTo loc_0092E0D1
  loc_0092E039: var_eax = Unknown_VTable_Call[eax+0000009Ch]
  loc_0092E041: var_30 = Unknown_VTable_Call[eax+0000009Ch]
loc_0092E095:   cmdFileNames.Visible = True
loc_0092E09D:   var_30 = eax
loc_0092E0CC:   GoTo loc_0092E189
loc_0092E0D1:   'Referenced from: 0092E00E
  loc_0092E0F6: var_eax = Unknown_VTable_Call[eax+0000009Ch]
  loc_0092E0FE: var_30 = Unknown_VTable_Call[eax+0000009Ch]
loc_0092E152:   cmdFileNames.Visible = False
loc_0092E15A:   var_30 = eax
loc_0092E195:   GoTo loc_0092E1AA
loc_0092E1A9:   Exit Sub
loc_0092E1AA:   'Referenced from: 0092E195
loc_0092E1AA:   Exit Sub
  loc_0092E1B3: var_eax = Unknown_VTable_Call[eax+00000008h]
loc_0092E1C6:   leaved
End Sub

Private Sub chkPrinter_Click() '92E9AD
  Dim var_18 As CommonDialog
loc_0092EA26:   var_24 = chkPrinter.Value
loc_0092EA54:   setz al
loc_0092EA6B:   If var_28 = 0 Then GoTo loc_0092EA9A
  loc_0092EA8A: var_18 = var_18._Action
loc_0092EA9A:   'Referenced from: 0092EA6B
loc_0092EAA6:   GoTo loc_0092EAB1
loc_0092EAB0:   Exit Sub
loc_0092EAB1:   'Referenced from: 0092EAA6
End Sub

Private Sub chkAccess_Click() '92D9F1
loc_0092DA62:   var_24 = chkDisk.Value
loc_0092DA6A:   var_30 = var_24
loc_0092DAB8:   var_28 = chkAccess.Value
loc_0092DAC0:   var_38 = var_28
  loc_0092DAEB: 0001h = 0001h - var_24
  loc_0092DAF9: 0001h = 0001h - var_28
  loc_0092DB03: 0001h = 0001h *
loc_0092DB4A:   var_24 = chkExcel.Value
loc_0092DB52:   var_30 = var_24
loc_0092DBA0:   var_28 = chkFlat.Value
loc_0092DBA8:   var_38 = var_28
  loc_0092DBD3: 0001h = 0001h - var_24
  loc_0092DBE1: var_18 = var_18 * 0001h
  loc_0092DBEF: 0001h = 0001h - var_28
  loc_0092DBF9: var_18 = var_18 * 0001h
loc_0092DC03:   var_18 = var_18
loc_0092DC1F:   If var_18 <> 0 Then GoTo loc_0092DCE2
  loc_0092DC4A: var_eax = Unknown_VTable_Call[eax+0000009Ch]
  loc_0092DC52: var_30 = Unknown_VTable_Call[eax+0000009Ch]
loc_0092DCA6:   cmdFileNames.Visible = True
loc_0092DCAE:   var_30 = eax
loc_0092DCDD:   GoTo loc_0092DD9A
loc_0092DCE2:   'Referenced from: 0092DC1F
  loc_0092DD07: var_eax = Unknown_VTable_Call[eax+0000009Ch]
  loc_0092DD0F: var_30 = Unknown_VTable_Call[eax+0000009Ch]
loc_0092DD63:   cmdFileNames.Visible = False
loc_0092DD6B:   var_30 = eax
loc_0092DDA6:   GoTo loc_0092DDBB
loc_0092DDBA:   Exit Sub
loc_0092DDBB:   'Referenced from: 0092DDA6
loc_0092DDBB:   Exit Sub
  loc_0092DDC4: var_eax = Unknown_VTable_Call[eax+00000008h]
loc_0092DDD7:   leaved
End Sub

Private Sub chkExcel_Click() '92E1CF
loc_0092E240:   var_24 = chkDisk.Value
loc_0092E248:   var_30 = var_24
loc_0092E296:   var_28 = chkAccess.Value
loc_0092E29E:   var_38 = var_28
  loc_0092E2C9: 0001h = 0001h - var_24
  loc_0092E2D7: 0001h = 0001h - var_28
  loc_0092E2E1: 0001h = 0001h *
loc_0092E328:   var_24 = chkExcel.Value
loc_0092E330:   var_30 = var_24
loc_0092E37E:   var_28 = chkFlat.Value
loc_0092E386:   var_38 = var_28
  loc_0092E3B1: 0001h = 0001h - var_24
  loc_0092E3BF: var_18 = var_18 * 0001h
  loc_0092E3CD: 0001h = 0001h - var_28
  loc_0092E3D7: var_18 = var_18 * 0001h
loc_0092E3E1:   var_18 = var_18
loc_0092E3FD:   If var_18 <> 0 Then GoTo loc_0092E4C0
  loc_0092E428: var_eax = Unknown_VTable_Call[eax+0000009Ch]
  loc_0092E430: var_30 = Unknown_VTable_Call[eax+0000009Ch]
loc_0092E484:   cmdFileNames.Visible = True
loc_0092E48C:   var_30 = eax
loc_0092E4BB:   GoTo loc_0092E578
loc_0092E4C0:   'Referenced from: 0092E3FD
  loc_0092E4E5: var_eax = Unknown_VTable_Call[eax+0000009Ch]
  loc_0092E4ED: var_30 = Unknown_VTable_Call[eax+0000009Ch]
loc_0092E541:   cmdFileNames.Visible = False
loc_0092E549:   var_30 = eax
loc_0092E584:   GoTo loc_0092E599
loc_0092E598:   Exit Sub
loc_0092E599:   'Referenced from: 0092E584
loc_0092E599:   Exit Sub
  loc_0092E5A2: var_eax = Unknown_VTable_Call[eax+00000008h]
loc_0092E5B5:   leaved
End Sub

Private Sub chkFlat_Click() '92E5BE
loc_0092E62F:   var_24 = chkDisk.Value
loc_0092E637:   var_30 = var_24
loc_0092E685:   var_28 = chkAccess.Value
loc_0092E68D:   var_38 = var_28
  loc_0092E6B8: 0001h = 0001h - var_24
  loc_0092E6C6: 0001h = 0001h - var_28
  loc_0092E6D0: 0001h = 0001h *
loc_0092E717:   var_24 = chkExcel.Value
loc_0092E71F:   var_30 = var_24
loc_0092E76D:   var_28 = chkFlat.Value
loc_0092E775:   var_38 = var_28
  loc_0092E7A0: 0001h = 0001h - var_24
  loc_0092E7AE: var_18 = var_18 * 0001h
  loc_0092E7BC: 0001h = 0001h - var_28
  loc_0092E7C6: var_18 = var_18 * 0001h
loc_0092E7D0:   var_18 = var_18
loc_0092E7EC:   If var_18 <> 0 Then GoTo loc_0092E8AF
  loc_0092E817: var_eax = Unknown_VTable_Call[eax+0000009Ch]
  loc_0092E81F: var_30 = Unknown_VTable_Call[eax+0000009Ch]
loc_0092E873:   cmdFileNames.Visible = True
loc_0092E87B:   var_30 = eax
loc_0092E8AA:   GoTo loc_0092E967
loc_0092E8AF:   'Referenced from: 0092E7EC
  loc_0092E8D4: var_eax = Unknown_VTable_Call[eax+0000009Ch]
  loc_0092E8DC: var_30 = Unknown_VTable_Call[eax+0000009Ch]
loc_0092E930:   cmdFileNames.Visible = False
loc_0092E938:   var_30 = eax
loc_0092E973:   GoTo loc_0092E988
loc_0092E987:   Exit Sub
loc_0092E988:   'Referenced from: 0092E973
loc_0092E988:   Exit Sub
  loc_0092E991: var_eax = Unknown_VTable_Call[eax+00000008h]
loc_0092E9A4:   leaved
End Sub

Private Sub optno_Click() '948B9D
  loc_00948C0C: var_eax = Unknown_VTable_Call[eax+0000009Ch]
  loc_00948C14: var_20 = Unknown_VTable_Call[eax+0000009Ch]
loc_00948C68:   txtseed.Visible = False
loc_00948C70:   var_20 = eax
loc_00948CAB:   GoTo loc_00948CB6
loc_00948CB5:   Exit Sub
loc_00948CB6:   'Referenced from: 00948CAB
End Sub

Private Sub cmdHELP_Click() '9466F6
loc_0094678F:   var_18 = var_EE00AC & "\UserGuide2010.pdf"
  loc_0094679D: var_eax = OLE1.CreateLink var_18, var_2C
  loc_009467A5: var_34 = OLE1.CreateLink var_18, var_2C
  loc_0094681E: var_eax = OLE1.DoVerb var_2C
  loc_00946826: var_34 = OLE1.DoVerb var_2C
loc_00946861:   GoTo loc_00946874
loc_00946873:   Exit Sub
loc_00946874:   'Referenced from: 00946861
End Sub

Private Sub txthigh2_KeyPress(KeyAscii As Integer) '949F85
  loc_00949FD6: var_eax = call Proc_CDDE13(eax, edi, esi)
  loc_00949FE0: If call Proc_CDDE13(eax, edi, esi) <> 0 Then GoTo loc_00949FE9
loc_00949FE9:   'Referenced from: 00949FE0
loc_0094A00B:   leaved
End Sub

Private Sub txthigh2_LostFocus() '94A00F
  Dim var_E0 As TextBox
loc_0094A09A:   var_E4 = txthigh2.Text
loc_0094A0DF:   setg cl
loc_0094A104:   If var_E8 = 0 Then GoTo loc_0094AFEA
loc_0094A122:   var_E0 = var_5C
loc_0094A13A:   var_58 = txthigh2.Text
loc_0094A142:   var_E4 = var_58
loc_0094A222:   txthigh2.Text = CStr(Format(var_58, "###,##0"))
loc_0094A22A:   var_E4 = eax
loc_0094A2B5:   var_58 = txtlow2.Text
loc_0094A2BD:   var_E4 = var_58
loc_0094A31B:   var_FC = var_58
loc_0094A32B:   var_64 = var_FC
loc_0094A35E:   var_50 = Format(var_FC, "#####0")
loc_0094A3B4:   var_58 = txthigh2.Text
loc_0094A3BC:   var_E4 = var_58
loc_0094A41A:   var_100 = var_58
loc_0094A42A:   var_64 = var_100
loc_0094A45D:   var_54 = Format(var_100, "#####0")
  loc_0094A499: fsubr st0, real8 ptr var_12C
loc_0094A4C8:   var_4C = (var_50 + 1#)
loc_0094A4F6:   If (var_4C < 1) = 0 Then GoTo loc_0094A6FF
loc_0094A54F:   var_6C = "The high number must be more than the low number.  Re-enter both values."
loc_0094A5C2:   txthigh2.Text = vbNullString
loc_0094A5CA:   var_E4 = eax
loc_0094A63C:   txtlow2.Text = vbNullString
loc_0094A644:   var_E4 = eax
loc_0094A6B1:   var_eax = txtlow2.SetFocus
loc_0094A6B9:   var_E4 = txtlow2.SetFocus
loc_0094A6FA:   GoTo loc_0094B084
loc_0094A6FF:   'Referenced from: 0094A4F6
loc_0094A72F:   var_58 = txtlow.Text
loc_0094A737:   var_E4 = var_58
loc_0094A795:   var_104 = var_58
loc_0094A7A5:   var_64 = var_104
loc_0094A7D8:   var_50 = Format(var_104, "#####0")
loc_0094A82E:   var_58 = txthigh.Text
loc_0094A836:   var_E4 = var_58
loc_0094A894:   var_108 = var_58
loc_0094A8A4:   var_64 = var_108
loc_0094A8D7:   var_54 = Format(var_108, "######")
loc_0094A8FF:   On Error Resume Next
  loc_0094A91A: fsubr st0, real8 ptr var_148
loc_0094A949:   var_3C = (var_50 + 1#)
loc_0094A950:   On Error Resume Next
loc_0094A961:   var_ret_1 = var_3C * var_4C
loc_0094A9A2:   var_58 = txtseqorder.Text
loc_0094A9AA:   var_E4 = var_58
loc_0094A9F4:   eax = (var_58 = vbNullString) + 1
loc_0094A9F7:   var_E8 = (var_58 = vbNullString) + 1
loc_0094AA17:   If var_E8 = 0 Then GoTo loc_0094AA93
loc_0094AA4A:   txtseqorder.Text = var_006E9BFC
loc_0094AA52:   var_E4 = eax
loc_0094AA93:   'Referenced from: 0094AA17
loc_0094AAC3:   var_58 = txtspares.Text
loc_0094AACB:   var_E4 = var_58
loc_0094AB15:   eax = (var_58 = vbNullString) + 1
loc_0094AB18:   var_E8 = (var_58 = vbNullString) + 1
loc_0094AB38:   If var_E8 = 0 Then GoTo loc_0094ABB4
loc_0094AB6B:   txtspares.Text = var_006E9BFC
loc_0094AB73:   var_E4 = eax
loc_0094ABB4:   'Referenced from: 0094AB38
loc_0094ABE4:   var_58 = txtseqorder.Text
loc_0094ABEC:   var_E4 = var_58
loc_0094AC4A:   var_10C = var_58
loc_0094AC5A:   var_64 = var_10C
loc_0094AC8D:   var_50 = Format(var_10C, "#####0")
loc_0094ACE3:   var_58 = txtspares.Text
loc_0094ACEB:   var_E4 = var_58
loc_0094AD49:   var_110 = var_58
loc_0094AD59:   var_64 = var_110
loc_0094AD8C:   var_54 = Format(var_110, "#####0")
  loc_0094ADDD: fcomp real8 ptr [00EE041Ch]
loc_0094ADE5:   sahf
loc_0094ADE6:   If Err.Number <= 0 Then GoTo loc_0094AFEA
loc_0094AE3F:   var_6C = "The frame size is less than the number of requested random values.  Re-enter the quantities of random numbers to be generated."
loc_0094AEB2:   txtseqorder.Text = vbNullString
loc_0094AEBA:   var_E4 = eax
loc_0094AF2C:   txtspares.Text = vbNullString
loc_0094AF34:   var_E4 = eax
loc_0094AFA1:   var_eax = txtseqorder.SetFocus
loc_0094AFA9:   var_E4 = txtseqorder.SetFocus
loc_0094AFEA:   GoTo loc_0094B084
loc_0094B042:   var_6C = "You must specify all the low and high values."
loc_0094B084:   'Referenced from: 0094A6FA
loc_0094B084:   Exit Sub
loc_0094B08F:   GoTo loc_0094B0C2
loc_0094B0C1:   Exit Sub
loc_0094B0C2:   'Referenced from: 0094B08F
loc_0094B0EA:   Exit Sub
  loc_0094B0F3: var_eax = Unknown_VTable_Call[eax+00000008h]
loc_0094B106:   leaved
End Sub

Private Sub Form_Load() '948066
loc_009480EA:   frmRATSTATS.Visible = False
loc_009480F2:   var_20 = eax
  loc_00948121: var_eax = Unknown_VTable_Call[eax+00000350h]
loc_0094813E:   frmRATSTATS.CurrentX = NAN
loc_00948146:   var_20 = eax
loc_00948181:   GoTo loc_0094818C
loc_0094818B:   Exit Sub
loc_0094818C:   'Referenced from: 00948181
End Sub

Private Sub Form_QueryUnload(Cancel As Integer, UnloadMode As Integer) '9485F9
loc_0094866C:   leaved
End Sub

Private Sub Form_Activate() '9478D8
  Dim var_38 As Me
loc_0094795C:   frmRATSTATS.Visible = False
loc_00947964:   var_34 = eax
  loc_00947993: var_eax = Unknown_VTable_Call[eax+0000033Ch]
loc_009479BA:   var_34 = frmRATSTATS.MousePointer
loc_009479ED:   setg cl
loc_00947A0C:   If var_38 = 0 Then GoTo loc_00947B08
  loc_00947A1A: var_eax = Unknown_VTable_Call[eax+0000033Ch]
loc_00947A41:   var_34 = frmRATSTATS.MousePointer
  loc_00947A70: fcomp real8 ptr [00402700h]
loc_00947A78:   sahf
loc_00947A79:   If var_54 >= 0 Then GoTo loc_00947A84
loc_00947A82:   GoTo loc_00947A88
loc_00947A84:   'Referenced from: 00947A79
loc_00947A88:   'Referenced from: 00947A82
loc_00947A8D:   var_38 = var_58
loc_00947AA7:   If var_38 = 0 Then GoTo loc_00947B08
  loc_00947AB1: var_eax = Unknown_VTable_Call[eax+0000033Ch]
loc_00947AD1:   frmRATSTATS.MousePointer = vbNullString
loc_00947AD9:   var_34 = eax
loc_00947B11:   If var_EE0174 <> 0 Then GoTo loc_00947BCF
  loc_00947B1F: var_eax = Unknown_VTable_Call[eax+00000360h]
loc_00947B3C:   frmRATSTATS.WindowState = 0
loc_00947B44:   var_34 = eax
  loc_00947B7B: var_eax = Unknown_VTable_Call[eax+00000304h]
loc_00947B98:   frmRATSTATS.Enabled = False
loc_00947BA0:   var_34 = eax
  loc_00947BD7: var_eax = Unknown_VTable_Call[eax+00000330h]
loc_00947BF6:   var_28 = frmRATSTATS.CurrentX
loc_00947BFE:   var_34 = var_28
  loc_00947C2D: var_eax = Unknown_VTable_Call[eax+00000328h]
loc_00947C4C:   var_2C = frmRATSTATS.CurrentX
loc_00947C54:   var_3C = var_2C
  loc_00947C7F: 0001h = 0001h - var_28
  loc_00947C8D: 0001h = 0001h - var_2C
  loc_00947C97: 0001h = 0001h *
  loc_00947CBF: var_eax = Unknown_VTable_Call[eax+00000324h]
loc_00947CDE:   var_28 = frmRATSTATS.CurrentX
loc_00947CE6:   var_34 = var_28
  loc_00947D15: var_eax = Unknown_VTable_Call[eax+00000320h]
loc_00947D34:   var_2C = frmRATSTATS.CurrentX
loc_00947D3C:   var_3C = var_2C
  loc_00947D67: 0001h = 0001h - var_28
  loc_00947D75: var_18 = var_18 * 0001h
  loc_00947D83: 0001h = 0001h - var_2C
  loc_00947D8D: var_18 = var_18 * 0001h
loc_00947D97:   var_18 = var_18
  loc_00947DB5: var_eax = Unknown_VTable_Call[eax+00000360h]
loc_00947DDC:   var_34 = frmRATSTATS.WindowState
loc_00947E0A:   setz al
loc_00947E16:   setz cl
loc_00947E30:   If var_38 = 0 Then GoTo loc_00947EF3
  loc_00947E3E: var_eax = Unknown_VTable_Call[eax+0000035Ch]
loc_00947E5B:   frmRATSTATS.WindowState = CInt(-1)
loc_00947E63:   var_34 = eax
  loc_00947E9A: var_eax = Unknown_VTable_Call[eax+00000300h]
loc_00947EB7:   frmRATSTATS.Enabled = True
loc_00947EBF:   var_34 = eax
loc_00947EEE:   GoTo loc_00947FB7
loc_00947EF3:   'Referenced from: 00947E30
  loc_00947EFB: var_eax = Unknown_VTable_Call[eax+0000035Ch]
loc_00947F18:   frmRATSTATS.WindowState = 0
loc_00947F20:   var_34 = eax
  loc_00947F5D: var_eax = Unknown_VTable_Call[eax+00000300h]
loc_00947F7A:   frmRATSTATS.Enabled = False
loc_00947F82:   var_34 = eax
  loc_00947FBF: var_eax = Unknown_VTable_Call[eax+00000344h]
  loc_00947FDA: var_eax = Unknown_VTable_Call[eax+00000204h]
  loc_00947FE2: var_34 = Unknown_VTable_Call[eax+00000204h]
loc_00948024:   GoTo loc_00948041
loc_00948040:   Exit Sub
loc_00948041:   'Referenced from: 00948024
loc_00948041:   Exit Sub
loc_0094805D:   leaved
End Sub

Private Sub Frame2_DragDrop(Source As Empty, X As Single, Y As Single) '948670
  Dim var_B0 As TextBox
loc_009486EC:   var_18 = txtlow.Text
loc_009486F4:   var_AC = var_18
loc_0094875D:   var_1C = txthigh.Text
loc_00948765:   var_B4 = var_1C
loc_009487AC:   esi = Len(var_18) + 1
loc_009487BB:   eax = Len(var_1C) + 1
loc_009487C1:   var_B8 = Len(var_1C) + 1
loc_009487F5:   If var_B8 = 0 Then GoTo loc_0094886B
loc_00948835:   var_34 = "Supply values for low number and/or high number --first set"
loc_0094886B:   'Referenced from: 009487F5
loc_0094889B:   var_18 = txtlow2.Text
loc_009488A3:   var_AC = var_18
loc_0094890C:   var_1C = txthigh2.Text
loc_00948914:   var_B4 = var_1C
loc_0094895B:   esi = Len(var_18) + 1
loc_0094896A:   eax = Len(var_1C) + 1
loc_00948970:   var_B8 = Len(var_1C) + 1
loc_009489A4:   If var_B8 = 0 Then GoTo loc_00948A1A
loc_009489E4:   var_34 = "Supply values for low number and/or high number -- second set"
loc_00948A1A:   'Referenced from: 009489A4
loc_00948A4A:   var_18 = txtseqorder.Text
loc_00948A52:   var_AC = var_18
loc_00948A97:   eax = Len(var_18) + 1
loc_00948A9A:   var_B0 = Len(var_18) + 1
loc_00948ABA:   If var_B0 = 0 Then GoTo loc_00948B30
loc_00948AFA:   var_34 = "Enter the quantity of numbers to be generated"
loc_00948B30:   'Referenced from: 00948ABA
loc_00948B3C:   GoTo loc_00948B7D
loc_00948B7C:   Exit Sub
loc_00948B7D:   'Referenced from: 00948B3C
End Sub

Private Sub txthigh_KeyPress(KeyAscii As Integer) '94980B
  loc_0094985C: var_eax = call Proc_CDDE13(eax, edi, esi)
  loc_00949866: If call Proc_CDDE13(eax, edi, esi) <> 0 Then GoTo loc_0094986F
loc_0094986F:   'Referenced from: 00949866
loc_00949891:   leaved
End Sub

Private Sub txthigh_LostFocus() '949895
  Dim var_B8 As TextBox
loc_00949919:   var_BC = txthigh.Text
loc_0094995E:   setg cl
loc_00949983:   If var_C0 = 0 Then GoTo loc_00949F0E
loc_009499A1:   var_B8 = var_34
loc_009499B9:   var_30 = txthigh.Text
loc_009499C1:   var_BC = var_30
loc_00949A9B:   txthigh.Text = CStr(Format(var_30, "###,##0"))
loc_00949AA3:   var_BC = eax
loc_00949B2E:   var_30 = txtlow.Text
loc_00949B36:   var_BC = var_30
loc_00949B91:   var_CC = var_30
loc_00949BA1:   var_3C = var_CC
loc_00949BCE:   var_28 = Format(var_CC, "#####0")
loc_00949C21:   var_30 = txthigh.Text
loc_00949C29:   var_BC = var_30
loc_00949C84:   var_D0 = var_30
loc_00949C94:   var_3C = var_D0
loc_00949CC1:   var_2C = Format(var_D0, "#####0")
  loc_00949CFA: fsubr st0, real8 ptr var_EC
  loc_00949D1C: fcomp real8 ptr [00402700h]
loc_00949D24:   sahf
loc_00949D25:   If Err.Number >= 0 Then GoTo loc_00949F0E
loc_00949D6F:   var_44 = "The high number must be more than the low number.  Re-enter both values."
loc_00949DD6:   txthigh.Text = vbNullString
loc_00949DDE:   var_BC = eax
loc_00949E50:   txtlow.Text = vbNullString
loc_00949E58:   var_BC = eax
loc_00949EC5:   var_eax = txtlow.SetFocus
loc_00949ECD:   var_BC = txtlow.SetFocus
loc_00949F1B:   GoTo loc_00949F48
loc_00949F47:   Exit Sub
loc_00949F48:   'Referenced from: 00949F1B
loc_00949F60:   Exit Sub
  loc_00949F69: var_eax = Unknown_VTable_Call[eax+00000008h]
loc_00949F7C:   leaved
End Sub

Private Sub txtseed_KeyPress(KeyAscii As Integer) '94B6DF
  loc_0094B730: var_eax = call Proc_CDDDBE(eax, edi, esi)
  loc_0094B73A: If call Proc_CDDDBE(eax, edi, esi) <> 0 Then GoTo loc_0094B743
loc_0094B743:   'Referenced from: 0094B73A
loc_0094B765:   leaved
End Sub

Private Sub txtseed_LostFocus() '94B769
  Dim var_B8 As TextBox
loc_0094B7ED:   var_BC = txtseed.Text
loc_0094B832:   setg cl
loc_0094B857:   If var_C0 = 0 Then GoTo loc_0094BC20
loc_0094B88D:   var_2C = txtseed.Text
loc_0094B895:   var_BC = var_2C
loc_0094B8E4:   var_28 = var_2C
loc_0094B90A:   var_8C = Len(var_28)
loc_0094B955:   For var_24 = 1 To Len(var_28) Step 1
loc_0094B95A:   var_F0 = var_24
loc_0094B960:   GoTo loc_0094BC13
loc_0094B965:
loc_0094B98E:   var_2C = Mid$(var_28, CLng(var_24), 1)
loc_0094B9A2:   eax = (var_2C = var_006EA9C8) + 1
loc_0094B9A5:   var_B8 = (var_2C = var_006EA9C8) + 1
loc_0094B9C5:   If var_B8 = 0 Then GoTo loc_0094B9CC
loc_0094B9C7:   GoTo loc_0094BBF6
loc_0094B9CC:   'Referenced from: 0094B9C5
loc_0094BA03:   var_2C = Mid$(var_28, CLng(var_24), 1)
loc_0094BA17:   setl bl
loc_0094BA37:   var_30 = Mid$(var_28, CLng(var_24), 1)
loc_0094BA4B:   setg cl
loc_0094BA87:   If var_B8 = 0 Then GoTo loc_0094BBF6
loc_0094BABE:   txtseed.Text = vbNullString
loc_0094BAC6:   var_BC = eax
loc_0094BB4B:   var_44 = "Re-enter the seed number."
loc_0094BBAD:   var_eax = txtseed.SetFocus
loc_0094BBB5:   var_BC = txtseed.SetFocus
loc_0094BC08:   Next var_24
  loc_0094BC0D: var_F0 = Next var_24
loc_0094BC13:   'Referenced from: 0094B960
loc_0094BC1A:   If var_F0 <> 0 Then GoTo loc_0094B965
loc_0094BC20:   'Referenced from: 0094B857
loc_0094BC2C:   GoTo loc_0094BC63
loc_0094BC62:   Exit Sub
loc_0094BC63:   'Referenced from: 0094BC2C
End Sub

Private Sub Command3_Click() '9477C3
  loc_00947883: var_eax = frmFileNames.Show 1, var_20
  loc_0094788B: var_3C = frmFileNames.Show 1, var_20
loc_009478D4:   leaved
End Sub

Private Sub cmdcontinue_Click() '92EAD1
  Dim var_470 As Variant
  Dim var_478 As Variant
  Dim var_480 As CheckBox
  Dim var_328 As Variant
  Dim var_32C As Variant
  Dim var_314 As CommonDialog
  Dim var_474 As Variant
  Dim var_154 As Variant
  Dim var_47C As Variant
  Dim var_4C As DBEngine
  Dim var_70 As DBEngine
loc_0092EB39:   Dim var_8C(2) As Long
loc_0092EB4C:   Dim var_A8(2) As Long
loc_0092EB5F:   Dim var_D8(6) As Long
loc_0092EB72:   Dim var_FC(500, 500) As Long
loc_0092EB85:   Dim var_134(10000) As Double
loc_0092EB98:   Dim var_16C(10000) As Double
loc_0092EBAB:   Dim var_188(10000) As Double
loc_0092EBBE:   Dim var_1AC(10000) As Double
loc_0092EBD1:   Dim var_228(10000) As Long
loc_0092EBE4:   Dim var_25C(10000) As Long
loc_0092EBF7:   Dim var_278(2) As Long
loc_0092EC0A:   Dim var_2E8(500) As Integer
loc_0092EC31:   var_470 = var_328
loc_0092EC4C:   var_31C = txthigh2.Text
loc_0092EC54:   var_474 = var_31C
loc_0092ECB1:   var_6C = var_31C
loc_0092ED56:   txthigh2.Text = CStr(Format(var_6C, "###,##0"))
loc_0092ED5E:   var_474 = eax
loc_0092EE02:   var_31C = txtlow2.Text
loc_0092EE0A:   var_474 = var_31C
loc_0092EE6E:   var_530 = var_31C
loc_0092EE81:   var_340 = var_530
loc_0092EEBB:   var_2A0 = Format(var_530, "#####0")
loc_0092EF20:   var_31C = txthigh2.Text
loc_0092EF28:   var_474 = var_31C
loc_0092EF8C:   var_534 = var_31C
loc_0092EF9F:   var_340 = var_534
  loc_0092F00F: call __vbaR8ErrVar(Format(var_534, "#####0"), 00000001h, 00000001h, var_328, Format(var_534, "#####0"), Me, 00000001h, 00000001h, var_328, Format(var_534, "#####0"), Me, 00000001h, 00000001h, var_328)
  loc_0092F021: call __vbaR8ErrVar(var_2A0)
  loc_0092F026: fsubr st0, real8 ptr var_5E0
  loc_0092F058: var_210 = __vbaR8ErrVar(var_2A0)
loc_0092F09A:   var_31C = txtlow.Text
loc_0092F0A2:   var_474 = var_31C
loc_0092F106:   var_538 = var_31C
loc_0092F119:   var_340 = var_538
loc_0092F153:   var_2A0 = Format(var_538, "#####0")
loc_0092F1B8:   var_31C = txthigh.Text
loc_0092F1C0:   var_474 = var_31C
loc_0092F224:   var_53C = var_31C
loc_0092F237:   var_340 = var_53C
  loc_0092F2A7: call __vbaR8ErrVar(Format(var_53C, "######"), 00000001h, 00000001h, var_328, Format(var_53C, "######"), Me, 00000001h, 00000001h, var_328, Format(var_53C, "######"), Me)
  loc_0092F2B9: call __vbaR8ErrVar(var_2A0)
  loc_0092F2BE: fsubr st0, real8 ptr var_5F0
  loc_0092F311: var_ret_1 = __vbaR8ErrVar(var_2A0) * var_210
loc_0092F35F:   var_31C = txtseqorder.Text
loc_0092F367:   var_474 = var_31C
loc_0092F3CB:   var_540 = var_31C
loc_0092F3DE:   var_340 = var_540
loc_0092F418:   var_2A0 = Format(var_540, "#####0")
loc_0092F47D:   var_31C = txtspares.Text
loc_0092F485:   var_474 = var_31C
loc_0092F4E9:   var_544 = var_31C
loc_0092F4FC:   var_340 = var_544
  loc_0092F56C: call __vbaR8ErrVar(var_2A0, 00000001h, 00000001h, var_328, var_2A0, Me, 00000001h, 00000001h, var_328, var_2A0, Me)
  loc_0092F57E: call __vbaR8ErrVar(Format(var_544, "#####0"))
  loc_0092F598: fcomp real8 ptr [00EE041Ch]
loc_0092F5A0:   sahf
loc_0092F5A1:   If Err.Number <= 0 Then GoTo loc_0092F8E9
  loc_0092F5FF: var_328 = Global.Screen
loc_0092F604:   var_474 = var_328
  loc_0092F65D: Global.MousePointer = var_ret_2
loc_0092F662:   var_47C = eax
loc_0092F706:   var_348 = "The frame size is less than the number of requested random values.  Re-enter the quantities of random numbers to be generated."
loc_0092F78F:   txtseqorder.Text = vbNullString
loc_0092F797:   var_474 = eax
loc_0092F816:   txtspares.Text = vbNullString
loc_0092F81E:   var_474 = eax
loc_0092F898:   var_eax = txtseqorder.SetFocus
loc_0092F8A0:   var_474 = txtseqorder.SetFocus
loc_0092F8E4:   GoTo loc_009458DB
loc_0092F8E9:   'Referenced from: 0092F5A1
loc_0092F926:   var_31C = txthigh.Text
loc_0092F92E:   var_474 = var_31C
loc_0092F97B:   eax = (var_31C = vbNullString) + 1
loc_0092F97E:   var_478 = (var_31C = vbNullString) + 1
loc_0092F9A4:   If var_478 = 0 Then GoTo loc_0092FB5C
loc_0092FA0D:   var_348 = "You need to enter the high number for the first set."
  loc_0092FAB3: var_328 = Global.Screen
loc_0092FAB8:   var_474 = var_328
  loc_0092FB11: Global.MousePointer = 00000001h
loc_0092FB16:   var_47C = eax
loc_0092FB57:   GoTo loc_009458DB
loc_0092FB5C:   'Referenced from: 0092F9A4
loc_0092FB99:   var_31C = txtlow.Text
loc_0092FBA1:   var_474 = var_31C
loc_0092FBEE:   eax = (var_31C = vbNullString) + 1
loc_0092FBF1:   var_478 = (var_31C = vbNullString) + 1
loc_0092FC17:   If var_478 = 0 Then GoTo loc_0092FDCF
loc_0092FC80:   var_348 = "You need to enter the low number for the first set."
  loc_0092FD26: var_328 = Global.Screen
loc_0092FD2B:   var_474 = var_328
  loc_0092FD84: Global.MousePointer = 00000001h
loc_0092FD89:   var_47C = eax
loc_0092FDCA:   GoTo loc_009458DB
loc_0092FDCF:   'Referenced from: 0092FC17
loc_0092FE0C:   var_31C = txthigh2.Text
loc_0092FE14:   var_474 = var_31C
loc_0092FE61:   eax = (var_31C = vbNullString) + 1
loc_0092FE64:   var_478 = (var_31C = vbNullString) + 1
loc_0092FE8A:   If var_478 = 0 Then GoTo loc_00930042
loc_0092FEF3:   var_348 = "You need to enter the high number for the second set."
  loc_0092FF99: var_328 = Global.Screen
loc_0092FF9E:   var_474 = var_328
  loc_0092FFF7: Global.MousePointer = 00000001h
loc_0092FFFC:   var_47C = eax
loc_0093003D:   GoTo loc_009458DB
loc_00930042:   'Referenced from: 0092FE8A
loc_0093007F:   var_31C = txtlow2.Text
loc_00930087:   var_474 = var_31C
loc_009300D4:   eax = (var_31C = vbNullString) + 1
loc_009300D7:   var_478 = (var_31C = vbNullString) + 1
loc_009300FD:   If var_478 = 0 Then GoTo loc_009302B5
loc_00930166:   var_348 = "You need to enter the low number for the second set."
  loc_0093020C: var_328 = Global.Screen
loc_00930211:   var_474 = var_328
  loc_0093026A: Global.MousePointer = 00000001h
loc_0093026F:   var_47C = eax
loc_009302B0:   GoTo loc_009458DB
loc_009302B5:   'Referenced from: 009300FD
loc_009302F2:   var_31C = txtseqorder.Text
loc_009302FA:   var_474 = var_31C
loc_00930347:   eax = (var_31C = vbNullString) + 1
loc_0093034A:   var_478 = (var_31C = vbNullString) + 1
loc_00930370:   If var_478 = 0 Then GoTo loc_009303FD
loc_009303B1:   txtseqorder.Text = var_006E9BFC
loc_009303B9:   var_474 = eax
loc_009303FD:   'Referenced from: 00930370
loc_0093043A:   var_31C = txtspares.Text
loc_00930442:   var_474 = var_31C
loc_0093048F:   eax = (var_31C = vbNullString) + 1
loc_00930492:   var_478 = (var_31C = vbNullString) + 1
loc_009304B8:   If var_478 = 0 Then GoTo loc_00930545
loc_009304F9:   txtspares.Text = var_006E9BFC
loc_00930501:   var_474 = eax
loc_00930545:   'Referenced from: 009304B8
loc_00930582:   var_42C = chkDisk.Value
loc_0093058A:   var_474 = var_42C
loc_009305F9:   var_430 = chkPrinter.Value
loc_00930601:   var_47C = var_430
loc_00930670:   var_434 = chkAccess.Value
loc_00930678:   var_484 = var_434
loc_009306E7:   var_438 = chkExcel.Value
loc_009306EF:   var_48C = var_438
loc_0093075E:   var_43C = chkFlat.Value
loc_00930766:   var_494 = var_43C
  loc_009307A3: 0001h = 0001h - var_42C
  loc_009307B4: 0001h = 0001h - var_430
  loc_009307C1: 0001h = 0001h *
  loc_009307CF: 0001h = 0001h - var_434
  loc_009307DC: 0001h = 0001h *
  loc_009307EA: 0001h = 0001h - var_438
  loc_009307F7: 0001h = 0001h *
  loc_00930805: 0001h = 0001h - var_43C
  loc_00930812: 0001h = 0001h *
loc_0093085F:   If var_118 <> 1 Then GoTo loc_00930A17
loc_009308C8:   var_348 = "You need to specify an output format in the OUTPUT TO box."
  loc_0093096E: var_328 = Global.Screen
loc_00930973:   var_474 = var_328
  loc_009309CC: Global.MousePointer = 00000001h
loc_009309D1:   var_47C = eax
loc_00930A12:   GoTo loc_009458DB
loc_00930A17:   'Referenced from: 0093085F
loc_00930A49:   var_290 = "ON"
loc_00930A8B:   var_31C = txtauditname.Text
loc_00930A93:   var_474 = var_31C
loc_00930AEA:   ecx = var_31C
loc_00930B37:   var_31C = txtseqorder.Text
loc_00930B3F:   var_474 = var_31C
loc_00930BA3:   var_54C = var_31C
loc_00930BB6:   var_340 = var_54C
loc_00930BF0:   var_2A0 = Format(var_54C, "#####0")
loc_00930C55:   var_31C = txtspares.Text
loc_00930C5D:   var_474 = var_31C
loc_00930CC1:   var_550 = var_31C
loc_00930CD4:   var_340 = var_550
  loc_00930D44: call __vbaR8ErrVar(var_2A0, 00000001h, 00000001h, var_328, var_2A0, Me, 00000001h, 00000001h, var_328, var_2A0, Me, var_328, var_2A0, Me)
  loc_00930D4E: var_EE085C = CInt()
  loc_00930D62: call __vbaR8ErrVar(Format(var_550, "#####0"))
  loc_00930D6C: var_EE085E = CInt()
loc_00930DAF:   var_31C = txtlow.Text
loc_00930DB7:   var_474 = var_31C
loc_00930E1B:   var_554 = var_31C
loc_00930E2E:   var_340 = var_554
loc_00930E68:   var_2A0 = Format(var_554, "#####0")
loc_00930ECD:   var_31C = txthigh.Text
loc_00930ED5:   var_474 = var_31C
loc_00930F39:   var_558 = var_31C
loc_00930F4C:   var_340 = var_558
loc_00930F86:   var_2D0 = Format(var_558, "######")
loc_00930FC6:   If var_470 >= 3 Then GoTo loc_00930FD1
loc_00930FCF:   GoTo loc_00930FDC
loc_00930FD1:   'Referenced from: 00930FC6
loc_00930FD1:   var_eax = Err.Raise
loc_00930FD6:   var_6A0 = Err.Raise
loc_00930FDC:   'Referenced from: 00930FCF
  loc_00930FE3: call __vbaR8ErrVar(var_2A0, 00000001h, 00000001h, var_328, var_2A0, Me, 00000001h, 00000001h, var_328, var_2A0, Me)
loc_00931014:   If var_470 >= 3 Then GoTo loc_0093101F
loc_0093101D:   GoTo loc_0093102A
loc_0093101F:   'Referenced from: 00931014
loc_0093101F:   var_eax = Err.Raise
loc_00931024:   var_6A4 = Err.Raise
loc_0093102A:   'Referenced from: 0093101D
  loc_00931031: call __vbaR8ErrVar(var_2D0)
loc_00931087:   var_31C = txtlow2.Text
loc_0093108F:   var_474 = var_31C
loc_009310F3:   var_55C = var_31C
loc_00931106:   var_340 = var_55C
loc_00931140:   var_2A0 = Format(var_55C, "#####0")
loc_009311A5:   var_31C = txthigh2.Text
loc_009311AD:   var_474 = var_31C
loc_00931211:   var_560 = var_31C
loc_00931224:   var_340 = var_560
loc_0093125E:   var_2D0 = Format(var_560, "######")
loc_0093129E:   If var_470 >= 3 Then GoTo loc_009312A9
loc_009312A7:   GoTo loc_009312B4
loc_009312A9:   'Referenced from: 0093129E
loc_009312A9:   var_eax = Err.Raise
loc_009312AE:   var_6B0 = Err.Raise
loc_009312B4:   'Referenced from: 009312A7
  loc_009312BB: call __vbaR8ErrVar(var_2A0, 00000001h, 00000001h, var_328, var_2A0, Me, 00000001h, 00000001h, var_328, var_2A0, Me)
loc_009312EC:   If var_470 >= 3 Then GoTo loc_009312F7
loc_009312F5:   GoTo loc_00931302
loc_009312F7:   'Referenced from: 009312EC
loc_009312F7:   var_eax = Err.Raise
loc_009312FC:   var_6B4 = Err.Raise
loc_00931302:   'Referenced from: 009312F5
  loc_00931309: call __vbaR8ErrVar(var_2D0)
loc_0093133A:   If var_474 >= 3 Then GoTo loc_00931345
loc_00931343:   GoTo loc_00931350
loc_00931345:   'Referenced from: 0093133A
loc_00931345:   var_eax = Err.Raise
loc_0093134A:   var_6B8 = Err.Raise
loc_00931350:   'Referenced from: 00931343
loc_00931361:   If var_478 >= 3 Then GoTo loc_0093136C
loc_0093136A:   GoTo loc_00931377
loc_0093136C:   'Referenced from: 00931361
loc_0093136C:   var_eax = Err.Raise
loc_00931371:   var_6BC = Err.Raise
loc_00931377:   'Referenced from: 0093136A
loc_00931388:   If var_470 >= 3 Then GoTo loc_00931393
loc_00931391:   GoTo loc_0093139E
loc_00931393:   'Referenced from: 00931388
loc_00931393:   var_eax = Err.Raise
loc_00931398:   var_6C0 = Err.Raise
loc_0093139E:   'Referenced from: 00931391
loc_009313B9:   ecx eax * 4 = ecx + eax * 4 - esi + edx * 4
  loc_009313C2: ecx+eax*4 = ecx+eax*4 + 00000001h
loc_009313EF:   If var_474 >= 3 Then GoTo loc_009313FA
loc_009313F8:   GoTo loc_00931405
loc_009313FA:   'Referenced from: 009313EF
loc_009313FA:   var_eax = Err.Raise
loc_009313FF:   var_6C4 = Err.Raise
loc_00931405:   'Referenced from: 009313F8
loc_00931416:   If var_478 >= 3 Then GoTo loc_00931421
loc_0093141F:   GoTo loc_0093142C
loc_00931421:   'Referenced from: 00931416
loc_00931421:   var_eax = Err.Raise
loc_00931426:   var_6C8 = Err.Raise
loc_0093142C:   'Referenced from: 0093141F
loc_0093143D:   If var_470 >= 3 Then GoTo loc_00931448
loc_00931446:   GoTo loc_00931453
loc_00931448:   'Referenced from: 0093143D
loc_00931448:   var_eax = Err.Raise
loc_0093144D:   var_6CC = Err.Raise
loc_00931453:   'Referenced from: 00931446
loc_0093146E:   ecx eax * 4 = ecx + eax * 4 - esi + edx * 4
  loc_00931477: ecx+eax*4 = ecx+eax*4 + 00000001h
loc_009314A4:   If var_470 >= 3 Then GoTo loc_009314AF
loc_009314AD:   GoTo loc_009314BA
loc_009314AF:   'Referenced from: 009314A4
loc_009314AF:   var_eax = Err.Raise
loc_009314B4:   var_6D0 = Err.Raise
loc_009314BA:   'Referenced from: 009314AD
loc_009314CB:   If var_474 >= 3 Then GoTo loc_009314D6
loc_009314D4:   GoTo loc_009314E1
loc_009314D6:   'Referenced from: 009314CB
loc_009314D6:   var_eax = Err.Raise
loc_009314DB:   var_6D4 = Err.Raise
loc_009314E1:   'Referenced from: 009314D4
loc_00931528:   var_3A0 = "courier new"
  loc_0093158D: var_328 = Global.Printer
loc_00931592:   var_474 = var_328
loc_009315F7:   var_348 = var_328.Font
  loc_009316AE: var_474 = Global.Printer
loc_00931703:   var_328 = var_328.FontSize
loc_00931758:   var_474 = chkDisk.Value
loc_0093179B:   setz al
loc_009317BB:   If var_478 = 0 Then GoTo loc_009318BF
loc_009317CA:   On Error Resume Next
  loc_0093181F: Open var_328._Action For Output As #3 Len = -1
loc_0093184E:   On Error Resume Next
  loc_00931896: ecx = var_328._Action
loc_009318BA:   On Error Resume Next
loc_009318BF:   'Referenced from: 009317BB
loc_00931904:   var_474 = chkFlat.Value
loc_00931947:   setz al
loc_00931967:   If var_478 = 0 Then GoTo loc_00931A00
  loc_009319B1: var_1FC = var_328._Action
loc_009319D5:   On Error Resume Next
loc_009319ED:   Open var_1FC For Output As #4 Len = -1
loc_009319FB:   On Error Resume Next
loc_00931A00:   'Referenced from: 00931967
loc_00931A45:   var_474 = chkAccess.Value
loc_00931A88:   setz al
loc_00931AA8:   If var_478 = 0 Then GoTo loc_00931D80
  loc_00931B06: var_328 = Global.Screen
loc_00931B0B:   var_474 = var_328
  loc_00931B64: Global.MousePointer = 00000001h
loc_00931B69:   var_47C = eax
  loc_00931BEE: var_110 = var_328._Action
loc_00931C18:   var_40 = "Enter the name of the Access table to be created in database "
loc_00931C37:   var_40 = var_40 & var_110
loc_00931C55:   var_40 = var_40 & ". For example, if you enter the table name OUT2STAGE, the two tables "
loc_00931C73:   var_40 = var_40 & "created will be OUT2STAGE-Values and OUT2STAGE-Spares."
loc_00931CFA:   var_3A0 = var_40
loc_00931D47:   ecx = InputBox(var_40, 10, 10, 10, 10, 10, 10)
loc_00931D80:   'Referenced from: 00931AA8
  loc_00931DD8: var_328 = Global.Screen
loc_00931DDD:   var_474 = var_328
  loc_00931E36: Global.MousePointer = 0000000Bh
loc_00931E3B:   var_47C = eax
loc_00931EC1:   var_474 = chkExcel.Value
loc_00931F04:   setz al
loc_00931F24:   If var_478 = 0 Then GoTo loc_00931F82
  loc_00931F67: var_5C = var_328._Action
loc_00931F82:   'Referenced from: 00931F24
  loc_00931F90: var_eax = GoSub var_518
  loc_00931F97: If GoSub var_518 <> 0 Then GoTo loc_00931F9B
loc_00931F99:   GoTo loc_00931FD8
loc_00931F9B:   'Referenced from: 00931F97
  loc_00931FA9: var_eax = GoSub var_518
  loc_00931FB0: If GoSub var_518 <> 0 Then GoTo loc_00931FB7
loc_00931FB2:   GoTo loc_00932943
loc_00931FB7:   'Referenced from: 00931FB0
  loc_00931FC5: var_eax = GoSub var_518
  loc_00931FCC: If GoSub var_518 <> 0 Then GoTo loc_00931FD3
loc_00931FCE:   GoTo loc_00933285
loc_00931FD3:   'Referenced from: 00931FCC
loc_00931FD3:   GoTo loc_00944F27
loc_00931FD8:   'Referenced from: 00931F99
loc_0093201D:   var_474 = optYes.Value
loc_00932094:   var_47C = txtseed.Text
loc_009320D7:   setz bl
loc_009320EB:   setg cl
loc_00932126:   If var_480 = 0 Then GoTo loc_009325EB
loc_00932171:   var_474 = txtseed.Text
  loc_009321DE: fcomp real8 ptr [004013A0h]
loc_009321E6:   sahf
loc_009321E7:   If var_728 > 0 Then GoTo loc_009323C9
  loc_00932245: var_328 = Global.Screen
loc_0093224A:   var_474 = var_328
  loc_009322A3: Global.MousePointer = 00000001h
loc_009322A8:   var_47C = eax
loc_0093234C:   var_348 = "The seed value must be positive."
loc_009323A3:   Close #3
loc_009323B1:   On Error Resume Next
loc_009323BF:   Close #4
loc_009323C4:   GoTo loc_009458DB
loc_009323C9:   'Referenced from: 009321E7
  loc_009323E9: call __vbaPowerR8(00000000, 40240000, 00000000, 402E0000, FFFFFFFFh, var_328, Close #4, Me, var_328, Close #4, Me, Close #4, Me, var_40, Me, 00000000h)
  loc_009323F3: fcomp real8 ptr [esi+00000034h]
loc_009323F8:   sahf
loc_009323F9:   If var_734 > 0 Then GoTo loc_009325E9
  loc_00932457: var_328 = Global.Screen
loc_0093245C:   var_474 = var_328
  loc_009324B5: Global.MousePointer = 00000001h
loc_009324BA:   var_47C = eax
loc_0093255E:   var_348 = "The seed value must be less than 10^15."
loc_009325B5:   On Error Resume Next
loc_009325C3:   Close #3
loc_009325D1:   On Error Resume Next
loc_009325DF:   Close #4
loc_009325E4:   GoTo loc_009458DB
loc_009325E9:   'Referenced from: 009323F9
loc_009325E9:   GoTo loc_009325FD
loc_009325EB:   'Referenced from: 00932126
loc_009325FD:   'Referenced from: 009325E9
loc_00932659:   var_348 = "#####.00"
loc_0093268B:   var_350 = Format$(Me, var_348)
loc_009326A2:   Randomize (Format$(Me, var_348))
loc_009326BF:
  loc_0093271A: fcomp real8 ptr [004013A0h]
loc_00932722:   sahf
loc_00932723:   If Err.Number <= 0 Then GoTo loc_00932731
loc_0093272F:   GoTo loc_00932738
loc_00932731:   'Referenced from: 00932723
loc_00932738:   'Referenced from: 0093272F
  loc_0093273E: fcomp real8 ptr [004026E0h]
loc_00932746:   sahf
loc_00932747:   If var_744 >= 0 Then GoTo loc_00932755
loc_00932753:   GoTo loc_0093275C
loc_00932755:   'Referenced from: 00932747
loc_0093275C:   'Referenced from: 00932753
loc_0093276A:   If var_748 <> 0 Then GoTo loc_00932771
loc_0093276C:   GoTo loc_009326BF
loc_00932771:   'Referenced from: 0093276A
loc_00932771:
  loc_009327CC: fcomp real8 ptr [004013A0h]
loc_009327D4:   sahf
loc_009327D5:   If Err.Number <= 0 Then GoTo loc_009327E3
loc_009327E1:   GoTo loc_009327EA
loc_009327E3:   'Referenced from: 009327D5
loc_009327EA:   'Referenced from: 009327E1
  loc_009327F0: fcomp real8 ptr [004026D0h]
loc_009327F8:   sahf
loc_009327F9:   If var_74C >= 0 Then GoTo loc_00932807
loc_00932805:   GoTo loc_0093280E
loc_00932807:   'Referenced from: 009327F9
loc_0093280E:   'Referenced from: 00932805
loc_0093281C:   If var_750 <> 0 Then GoTo loc_00932823
loc_0093281E:   GoTo loc_00932771
loc_00932823:   'Referenced from: 0093281C
loc_00932823:
  loc_0093287E: fcomp real8 ptr [004013A0h]
loc_00932886:   sahf
loc_00932887:   If Err.Number <= 0 Then GoTo loc_00932895
loc_00932893:   GoTo loc_0093289C
loc_00932895:   'Referenced from: 00932887
loc_0093289C:   'Referenced from: 00932893
  loc_009328A2: fcomp real8 ptr [004026C0h]
loc_009328AA:   sahf
loc_009328AB:   If var_754 >= 0 Then GoTo loc_009328B9
loc_009328B7:   GoTo loc_009328C0
loc_009328B9:   'Referenced from: 009328AB
loc_009328C0:   'Referenced from: 009328B7
loc_009328CE:   If var_758 <> 0 Then GoTo loc_009328D5
loc_009328D0:   GoTo loc_00932823
loc_009328D5:   'Referenced from: 009328CE
loc_009328E7:   var_1F0 = CLng(1)
loc_009328FF:   var_23C = CLng(1)
loc_00932917:   var_284 = CLng(-1)
  loc_0093293E: call Return(var_518, FFFFFFFFh)
loc_00932943:   'Referenced from: 00931FB2
loc_00932953:   If var_EE085C <> 0 Then GoTo loc_00933134
loc_0093299E:   var_474 = chkDisk.Value
loc_009329E1:   setz al
loc_00932A01:   If var_478 = 0 Then GoTo loc_00933134
  loc_00932A33: 00000050h = 00000050h - Len("Windows RAT-STATS")
loc_00932A83:   Print 3, CInt(var_328)
  loc_00932AB7: 00000050h = 00000050h - Len("Statistical Software")
  loc_00932B07: Print 3, CInt()
loc_00932BB1:   Print 3, "Date: " & Format$(Now, "m/d/yyyy")
loc_00932C05:   Print 3, "Random Number Generator"
loc_00932CAD:   Print 3, "Time: " & Format$(Now, "h:mm")
  loc_00932D25: 00000050h = 00000050h - Len("AUDIT: " & var_EE081C)
  loc_00932D5A: var_3C = CInt()
loc_00932D75:   Print 3, var_3C
loc_00932D90:   Print 3, vbNullString
loc_00932DAB:   Print 3, "SEED NUMBER: "
loc_00932DDF:   var_3A0 = vbNullString
loc_00932E36:   Print 3, Format$(vbNullString, "#####0.00")
loc_00932E53:   Print 3, 53
loc_00932E87:   var_3A0 = vbNullString
  loc_00932EDF: 0000000Fh = 0000000Fh - Len(Format$(vbNullString, "#,###,###,###"))
loc_00932F0D:   Print 3, 0; Fh
loc_00932F23:   Print 3
loc_00932F38:   Print 3
loc_00932F58:   Print 3, "     FILE OF RANDOM NUMBERS: "
loc_00932F6E:   Print 3
loc_00932F88:   Print 3, "     TOTAL RANDOM NUMBERS GENERATED: "
  loc_00932FC2: 00EE085Ch = 00EE085Ch + 00EE085Eh
loc_00933030:   Print 3, Format$(15599708, "##,###")
loc_00933046:   Print 3
loc_00933060:   Print 3, "THE NUMBERS ARE IN THE FOLLOWING FORMAT IN YOUR FILE:"
loc_0093307B:   Print 3, "   POSITIONS 1 THROUGH  6 - ORDER OF SELECTION"
loc_00933096:   Print 3, "   POSITIONS 7 THROUGH 17 - FIRST NUMBER OF SET"
loc_009330B1:   Print 3, "   POSITIONS 18 THROUGH 30 - SECOND NUMBER OF SET"
loc_009330CC:   Print 3, "EACH COLUMN OF NUMBERS IS RIGHT JUSTIFIED."
loc_009330E2:   Print 3
loc_009330F7:   Print 3
loc_00933111:   Print 3, "Selection   First       Second"
loc_0093312C:   Print 3, "  Order    Number       Number"
loc_00933134:   'Referenced from: 00932953
  loc_00933176: var_eax = GoSub var_518
  loc_0093317D: If GoSub var_518 <> 0 Then GoTo loc_00933184
loc_0093317F:   GoTo loc_00943610
loc_00933184:   'Referenced from: 0093317D
  loc_00933192: var_eax = GoSub var_518
  loc_00933199: If GoSub var_518 <> 0 Then GoTo loc_009331A0
loc_0093319B:   GoTo loc_00933FDF
loc_009331A0:   'Referenced from: 00933199
loc_009331B0:   If var_EE085E <> 0 Then GoTo loc_009331C5
  loc_009331C0: call Return(var_518)
loc_009331C5:   'Referenced from: 009331B0
  loc_009331D2: 00EE085Ch = 00EE085Ch + 0001h
  loc_009331F0: 00EE085Ch = 00EE085Ch + 00EE085Eh
loc_00933235:   var_290 = "OFF"
  loc_00933248: var_eax = GoSub var_518
  loc_0093324F: If GoSub var_518 <> 0 Then GoTo loc_00933256
loc_00933251:   GoTo loc_00943610
loc_00933256:   'Referenced from: 0093324F
  loc_00933264: var_eax = GoSub var_518
  loc_0093326B: If GoSub var_518 <> 0 Then GoTo loc_00933272
loc_0093326D:   GoTo loc_00933FDF
loc_00933272:   'Referenced from: 0093326B
  loc_00933280: call Return(var_518)
loc_00933285:   'Referenced from: 00931FCE
loc_009332CA:   var_474 = chkPrinter.Value
loc_0093330D:   setz al
loc_0093332D:   If var_478 = 0 Then GoTo loc_00933419
loc_00933345:   var_B8 = "YES"
  loc_00933358: var_eax = GoSub var_518
  loc_0093335F: If GoSub var_518 <> 0 Then GoTo loc_00933366
loc_00933361:   GoTo loc_00944A80
loc_00933366:   'Referenced from: 0093335F
  loc_009333BE: var_328 = Global.Printer
loc_009333C3:   var_474 = var_328
loc_00933419:   'Referenced from: 0093332D
loc_0093345E:   var_474 = chkDisk.Value
loc_009334A1:   setz al
loc_009334C1:   If var_478 = 0 Then GoTo loc_009334D1
loc_009334CC:   Close #3
loc_009334D1:   'Referenced from: 009334C1
loc_00933516:   var_474 = chkFlat.Value
loc_00933559:   setz al
loc_00933579:   If var_478 = 0 Then GoTo loc_00933589
loc_00933584:   Close #4
loc_00933589:   'Referenced from: 00933579
loc_009335CE:   var_474 = chkExcel.Value
loc_00933611:   setz al
loc_00933631:   If var_478 = 0 Then GoTo loc_00933AE9
loc_00933640:   On Error Resume Next
loc_00933655:   var_1BC = var_5C
  loc_0093366F: var_eax = call Proc_71_0_CDE27D(var_348, var_1BC, -1)
loc_00933688:   var_1EC = CInt(15599708)
loc_009336A5:   var_3A0 = var_1EC
loc_009336D9:   var_58 = LCase(var_1EC)
loc_009336FF:   If (var_58 <> ".xls") <> 0 Then GoTo loc_0093377F
loc_0093371A:   If (var_1EC <> ".XLS") <> 0 Then GoTo loc_00933740
loc_0093373B:   var_1BC = var_1BC & var_006EA904
loc_00933740:   'Referenced from: 0093371A
loc_00933759:   If (var_1EC <> ".xls") <> 0 Then GoTo loc_0093377F
loc_0093377A:   var_1BC = var_1BC & var_006EA90C
loc_0093377F:   'Referenced from: 009336FF
loc_00933791:   ecx = var_1BC
loc_009337A9:   var_10C = var_1BC
  loc_0093392B: var_eax = Unknown_VTable_Call[eax+00000224h]
  loc_00933933: var_470 = Unknown_VTable_Call[eax+00000224h]
loc_00933986:   var_470 = eax
loc_00933A51:   var_3A8 = CommonDialog3.FontItalic
loc_00933A56:   var_470 = var_3A8
  loc_00933A9A: call __vbaCastObj(00000000h, var_006EA920, var_3A4, var_3A0, var_39C, var_3A8, var_3A4, var_3A0, var_39C, var_470, Me, var_328, var_470, Me)
  loc_00933ABA: call __vbaCastObj(00000000h, var_006EA930, var_108, __vbaCastObj(00000000h, var_006EA920, var_3A4, var_3A0, var_39C, var_3A8, var_3A4, var_3A0, var_39C, var_470, Me, var_328, var_470, Me))
  loc_00933ADA: call __vbaCastObj(00000000h, var_006EA910, var_314, __vbaCastObj(00000000h, var_006EA930, var_108, __vbaCastObj(00000000h, var_006EA920, var_3A4, var_3A0, var_39C, var_3A8, var_3A4, var_3A0, var_39C, var_470, Me, var_328, var_470, Me)))
loc_00933AE9:   'Referenced from: 00933631
  loc_00933B41: var_328 = Global.Screen
loc_00933B46:   var_474 = var_328
  loc_00933B9F: Global.MousePointer = 00000001h
loc_00933BA4:   var_47C = eax
loc_00933C2A:   var_474 = chkAccess.Value
loc_00933C6D:   setz al
loc_00933C8D:   If var_478 = 0 Then GoTo loc_00933D62
loc_00933CFE:   var_340 = "Array has been transferred to output tables in Access database " & var_110 & var_006EA9C8
loc_00933D62:   'Referenced from: 00933C8D
loc_00933D9F:   var_42C = chkExcel.Value
loc_00933DA7:   var_474 = var_42C
loc_00933DEA:   setz al
loc_00933E0A:   If var_478 = 0 Then GoTo loc_00933EDC
loc_00933E68:   var_31C = "Array has been transferred to Excel workbook " & var_5C
loc_00933E78:   var_340 = var_31C & "X."
loc_00933EDC:   'Referenced from: 00933E0A
loc_00933EE5:   Close #6
loc_00933F27:   var_470 = eax
  loc_00933F8B: var_eax = frmOutTwo.Show var_3A8, var_3A4
  loc_00933F93: var_474 = frmOutTwo.Show var_3A8, var_3A4
  loc_00933FDA: call Return(var_518, var_3A0, var_39C, var_518, Me, var_74, __vbaCastObj(00000000h, var_006EA910, var_314, __vbaCastObj(00000000h, var_006EA930, var_108, __vbaCastObj(00000000h, var_006EA920, var_3A4, var_3A0, var_39C, var_3A8, var_3A4, var_3A0, var_39C, var_470, Me, var_328, var_470, Me))))
loc_00933FDF:   'Referenced from: 0093319B
loc_00933FED:   var_49C = var_1C0
loc_00934004:   var_234 = var_30C
loc_0093400B:   GoTo loc_00934028
loc_0093400D:
loc_00934014:   var_234 = var_234 + 1
loc_00934021:   var_234 = var_234
loc_00934028:   'Referenced from: 0093400B
loc_00934036:   If var_234 > 0 Then GoTo loc_009393AF
loc_00934050:
loc_00934070:   If var_EE0000 <> 0 Then GoTo loc_0093407A
loc_00934078:   GoTo loc_0093408B
loc_0093407A:   'Referenced from: 00934070
loc_0093408B:   'Referenced from: 00934078
loc_0093409A:   var_1E8 = CLng(var_4026B8)
loc_009340AD:   var_1E8 = var_1E8 * 177
loc_009340C7:   var_230 = var_1F0 - var_1E8
loc_009340DA:   var_230 = var_230 * 171
loc_009340FD:   var_1F0 = var_230 - var_1E8 * 2
loc_00934111:   If var_1F0 <= 0 Then GoTo loc_00934115
loc_00934113:   GoTo loc_00934133
loc_00934115:   'Referenced from: 00934111
  loc_00934122: var_1F0 = var_1F0 + 0000763Dh
loc_0093412D:   var_1F0 = var_1F0
loc_00934133:   'Referenced from: 00934113
loc_00934153:   If var_EE0000 <> 0 Then GoTo loc_0093415D
loc_0093415B:   GoTo loc_0093416E
loc_0093415D:   'Referenced from: 00934153
loc_0093416E:   'Referenced from: 0093415B
loc_0093417D:   var_1E8 = CLng(var_4026B0)
loc_00934190:   var_1E8 = var_1E8 * 176
loc_009341AA:   var_230 = var_23C - var_1E8 * 176
loc_009341BD:   var_230 = var_230 * 172
loc_009341E0:   var_23C = var_230 - var_1E8 * 35
loc_009341F4:   If var_23C <= 0 Then GoTo loc_009341F8
loc_009341F6:   GoTo loc_00934216
loc_009341F8:   'Referenced from: 009341F4
  loc_00934205: var_23C = var_23C + 00007663h
loc_00934210:   var_23C = var_23C
loc_00934216:   'Referenced from: 009341F6
loc_00934236:   If var_EE0000 <> 0 Then GoTo loc_00934240
loc_0093423E:   GoTo loc_00934251
loc_00934240:   'Referenced from: 00934236
loc_00934251:   'Referenced from: 0093423E
loc_00934260:   var_1E8 = CLng(var_4026A8)
loc_00934273:   var_1E8 = var_1E8 * 178
loc_0093428D:   var_230 = var_284 - var_1E8 * 178
loc_009342A0:   var_230 = var_230 * 170
loc_009342C3:   var_284 = var_230 - var_1E8 * 63
loc_009342D7:   If var_284 <= 0 Then GoTo loc_009342DB
loc_009342D9:   GoTo loc_009342F9
loc_009342DB:   'Referenced from: 009342D7
  loc_009342E8: var_284 = var_284 + 00007673h
loc_009342F3:   var_284 = var_284
loc_009342F9:   'Referenced from: 009342D9
loc_00934319:   If var_EE0000 <> 0 Then GoTo loc_00934323
loc_00934321:   GoTo loc_00934334
loc_00934323:   'Referenced from: 00934319
loc_00934334:   'Referenced from: 00934321
loc_0093434D:   If var_EE0000 <> 0 Then GoTo loc_00934357
loc_00934355:   GoTo loc_00934368
loc_00934357:   'Referenced from: 0093434D
loc_00934368:   'Referenced from: 00934355
loc_00934368:   faddp st1
loc_00934383:   If var_EE0000 <> 0 Then GoTo loc_0093438D
loc_0093438B:   GoTo loc_0093439E
loc_0093438D:   'Referenced from: 00934383
loc_0093439E:   'Referenced from: 0093438B
loc_0093439E:   faddp st1
loc_009343BD:   var_ret_E = Int(var_2C0)
  loc_009343C2: fsubr st0, real8 ptr var_2C0
loc_009343EE:   If (var_48 <> var_006EAF7C) <> 0 Then GoTo loc_009343F5
loc_009343F0:   GoTo loc_009344C0
loc_009343F5:   'Referenced from: 009343EE
loc_0093440D:   If var_470 >= 3 Then GoTo loc_00934418
loc_00934416:   GoTo loc_00934423
loc_00934418:   'Referenced from: 0093440D
loc_00934418:   var_eax = Err.Raise
loc_0093441D:   var_7F4 = Err.Raise
loc_00934423:   'Referenced from: 00934416
loc_00934434:   If var_474 >= 3 Then GoTo loc_0093443F
loc_0093443D:   GoTo loc_0093444A
loc_0093443F:   'Referenced from: 00934434
loc_0093443F:   var_eax = Err.Raise
loc_00934444:   var_7F8 = Err.Raise
loc_0093444A:   'Referenced from: 0093443D
loc_00934472:   var_ret_F = Int((var_B4 * var_800))
loc_009344A1:   var_1B8 = CLng((var_808))
loc_009344BB:   GoTo loc_00934050
loc_009344C0:   'Referenced from: 009343F0
loc_009344D8:   If var_470 >= 3 Then GoTo loc_009344E3
loc_009344E1:   GoTo loc_009344EE
loc_009344E3:   'Referenced from: 009344D8
loc_009344E3:   var_eax = Err.Raise
loc_009344E8:   var_80C = Err.Raise
loc_009344EE:   'Referenced from: 009344E1
loc_009344FF:   If var_474 >= 3 Then GoTo loc_0093450A
loc_00934508:   GoTo loc_00934515
loc_0093450A:   'Referenced from: 009344FF
loc_0093450A:   var_eax = Err.Raise
loc_0093450F:   var_810 = Err.Raise
loc_00934515:   'Referenced from: 00934508
loc_0093453D:   var_ret_10 = Int((var_B4 * var_818))
loc_0093456C:   var_1E4 = CLng((var_820))
loc_0093459E:   If var_470 >= 3 Then GoTo loc_009345A9
loc_009345A7:   GoTo loc_009345B4
loc_009345A9:   'Referenced from: 0093459E
loc_009345A9:   var_eax = Err.Raise
loc_009345AE:   var_824 = Err.Raise
loc_009345B4:   'Referenced from: 009345A7
loc_009345C5:   If var_474 >= 3 Then GoTo loc_009345D0
loc_009345CE:   GoTo loc_009345DB
loc_009345D0:   'Referenced from: 009345C5
loc_009345D0:   var_eax = Err.Raise
loc_009345D5:   var_828 = Err.Raise
loc_009345DB:   'Referenced from: 009345CE
loc_009345EC:   If var_478 >= 3 Then GoTo loc_009345F7
loc_009345F5:   GoTo loc_00934602
loc_009345F7:   'Referenced from: 009345EC
loc_009345F7:   var_eax = Err.Raise
loc_009345FC:   var_82C = Err.Raise
loc_00934602:   'Referenced from: 009345F5
loc_00934614:   var_1B8 = var_1B8 - ecx + eax * 4
loc_00934626:   var_1B8 = var_1B8 * ecx + eax * 4
loc_00934630:   var_1B8 = var_1B8 + var_1E4
loc_00934648:   var_1B8 = var_1B8 - ecx + eax * 4
  loc_00934651: var_1B8 = var_1B8 + 00000001h
loc_0093465A:   var_194 = var_1B8
loc_00934682:   GoTo loc_0093469F
loc_00934684:
loc_0093468B:   var_280 = var_280 + 1
loc_00934698:   var_280 = var_280
loc_0093469F:   'Referenced from: 00934682
loc_009346AD:   If var_280 > 0 Then GoTo loc_00934735
loc_009346CD:   var_838 = var_280
loc_009346EC:   If var_EE0000 <> 0 Then GoTo loc_009346F6
loc_009346F4:   GoTo loc_00934707
loc_009346F6:   'Referenced from: 009346EC
loc_00934707:   'Referenced from: 009346F4
  loc_0093471C: fcomp real8 ptr var_834
loc_00934724:   sahf
loc_00934725:   If Err.Number < 0 Then GoTo loc_00934729
loc_00934727:   GoTo loc_00934735
loc_00934729:   'Referenced from: 00934725
loc_00934730:   GoTo loc_00934684
loc_00934735:   'Referenced from: 009346AD
  loc_00934743: var_280 = var_280 * 0003h
  loc_0093474D: var_280 = var_280 - 0002h
loc_00934757:   var_190 = var_280
loc_0093476C:   var_470 = var_280
loc_0093477C:   If var_470 >= 501 Then GoTo loc_00934787
loc_00934785:   GoTo loc_00934792
loc_00934787:   'Referenced from: 0093477C
loc_00934787:   var_eax = Err.Raise
loc_0093478C:   var_844 = Err.Raise
loc_00934792:   'Referenced from: 00934785
loc_009347A2:   var_4AC = ecx + eax * 2
loc_009347BB:   GoTo loc_009347D8
loc_009347BD:
loc_009347C4:   var_2B8 = var_2B8 + 1
loc_009347D1:   var_2B8 = var_2B8
loc_009347D8:   'Referenced from: 009347BB
loc_009347E6:   If var_2B8 > 0 Then GoTo loc_00934A3E
loc_009347FA:   var_474 = var_2B8
loc_0093480A:   If var_474 >= 501 Then GoTo loc_00934815
loc_00934813:   GoTo loc_00934820
loc_00934815:   'Referenced from: 0093480A
loc_00934815:   var_eax = Err.Raise
loc_0093481A:   var_848 = Err.Raise
loc_00934820:   'Referenced from: 00934813
loc_00934827:   var_470 = var_190
loc_00934837:   If var_470 >= 501 Then GoTo loc_00934842
loc_00934840:   GoTo loc_0093484D
loc_00934842:   'Referenced from: 00934837
loc_00934842:   var_eax = Err.Raise
loc_00934847:   var_84C = Err.Raise
loc_0093484D:   'Referenced from: 00934840
loc_0093485F:   var_474 = var_474 + var_470 * 501
loc_00934870:   If var_1B8 >= 0 Then GoTo loc_00934877
loc_00934872:   GoTo loc_00934A43
loc_00934877:   'Referenced from: 00934870
loc_00934885:   var_474 = var_2B8
loc_00934895:   If var_474 >= 501 Then GoTo loc_009348A0
loc_0093489E:   GoTo loc_009348AB
loc_009348A0:   'Referenced from: 00934895
loc_009348A0:   var_eax = Err.Raise
loc_009348A5:   var_850 = Err.Raise
loc_009348AB:   'Referenced from: 0093489E
loc_009348B2:   var_470 = var_190
loc_009348C2:   If var_470 >= 501 Then GoTo loc_009348CD
loc_009348CB:   GoTo loc_009348D8
loc_009348CD:   'Referenced from: 009348C2
loc_009348CD:   var_eax = Err.Raise
loc_009348D2:   var_854 = Err.Raise
loc_009348D8:   'Referenced from: 009348CB
loc_009348EA:   var_474 = var_474 + var_470 * 501
loc_009348FB:   If var_1B8 <= 0 Then GoTo loc_00934902
loc_009348FD:   GoTo loc_00934A32
loc_00934902:   'Referenced from: 009348FB
loc_00934910:   var_474 = var_2B8
loc_00934920:   If var_474 >= 501 Then GoTo loc_0093492B
loc_00934929:   GoTo loc_00934936
loc_0093492B:   'Referenced from: 00934920
loc_0093492B:   var_eax = Err.Raise
loc_00934930:   var_858 = Err.Raise
loc_00934936:   'Referenced from: 00934929
  loc_0093493D: var_190 = var_190 + 0001h
loc_0093494A:   var_470 = var_190
loc_0093495A:   If var_470 >= 501 Then GoTo loc_00934965
loc_00934963:   GoTo loc_00934970
loc_00934965:   'Referenced from: 0093495A
loc_00934965:   var_eax = Err.Raise
loc_0093496A:   var_85C = Err.Raise
loc_00934970:   'Referenced from: 00934963
loc_00934982:   var_474 = var_474 + var_470 * 501
loc_00934993:   If var_1E4 >= 0 Then GoTo loc_0093499A
loc_00934995:   GoTo loc_00934A43
loc_0093499A:   'Referenced from: 00934993
loc_009349A8:   var_474 = var_2B8
loc_009349B8:   If var_474 >= 501 Then GoTo loc_009349C3
loc_009349C1:   GoTo loc_009349CE
loc_009349C3:   'Referenced from: 009349B8
loc_009349C3:   var_eax = Err.Raise
loc_009349C8:   var_860 = Err.Raise
loc_009349CE:   'Referenced from: 009349C1
  loc_009349D5: var_190 = var_190 + 0001h
loc_009349E2:   var_470 = var_190
loc_009349F2:   If var_470 >= 501 Then GoTo loc_009349FD
loc_009349FB:   GoTo loc_00934A08
loc_009349FD:   'Referenced from: 009349F2
loc_009349FD:   var_eax = Err.Raise
loc_00934A02:   var_864 = Err.Raise
loc_00934A08:   'Referenced from: 009349FB
loc_00934A1A:   var_474 = var_474 + var_470 * 501
loc_00934A2B:   If var_1E4 <> 0 Then GoTo loc_00934A32
loc_00934A2D:   GoTo loc_00934050
loc_00934A32:   'Referenced from: 009348FD
loc_00934A39:   GoTo loc_009347BD
loc_00934A3E:   'Referenced from: 009347E6
loc_00934A3E:   GoTo loc_00934E2F
loc_00934A43:   'Referenced from: 00934872
  loc_00934A51: var_2B8 = var_2B8 + 0001h
loc_00934A5B:   var_4B4 = var_2B8
loc_00934A71:   var_470 = var_280
loc_00934A81:   If var_470 >= 501 Then GoTo loc_00934A8C
loc_00934A8A:   GoTo loc_00934A97
loc_00934A8C:   'Referenced from: 00934A81
loc_00934A8C:   var_eax = Err.Raise
loc_00934A91:   var_868 = Err.Raise
loc_00934A97:   'Referenced from: 00934A8A
  loc_00934AA7: ecx+eax*2 = ecx+eax*2 + 0001h
loc_00934AB1:   var_308 = ecx + eax * 2
loc_00934AB8:   GoTo loc_00934AD5
loc_00934ABA:
loc_00934AC1:   var_308 = var_308 + var_4B0
loc_00934ACE:   var_308 = var_308
loc_00934AD5:   'Referenced from: 00934AB8
loc_00934AE3:   If var_308 < 0 Then GoTo loc_00934E2F
  loc_00934AF7: var_308 = var_308 - 0001h
loc_00934B04:   var_47C = var_308
loc_00934B14:   If var_47C >= 501 Then GoTo loc_00934B1F
loc_00934B1D:   GoTo loc_00934B2A
loc_00934B1F:   'Referenced from: 00934B14
loc_00934B1F:   var_eax = Err.Raise
loc_00934B24:   var_86C = Err.Raise
loc_00934B2A:   'Referenced from: 00934B1D
loc_00934B31:   var_478 = var_190
loc_00934B41:   If var_478 >= 501 Then GoTo loc_00934B4C
loc_00934B4A:   GoTo loc_00934B57
loc_00934B4C:   'Referenced from: 00934B41
loc_00934B4C:   var_eax = Err.Raise
loc_00934B51:   var_870 = Err.Raise
loc_00934B57:   'Referenced from: 00934B4A
loc_00934B5E:   var_474 = var_308
loc_00934B6E:   If var_474 >= 501 Then GoTo loc_00934B79
loc_00934B77:   GoTo loc_00934B84
loc_00934B79:   'Referenced from: 00934B6E
loc_00934B79:   var_eax = Err.Raise
loc_00934B7E:   var_874 = Err.Raise
loc_00934B84:   'Referenced from: 00934B77
loc_00934B8B:   var_470 = var_190
loc_00934B9B:   If var_470 >= 501 Then GoTo loc_00934BA6
loc_00934BA4:   GoTo loc_00934BB1
loc_00934BA6:   'Referenced from: 00934B9B
loc_00934BA6:   var_eax = Err.Raise
loc_00934BAB:   var_878 = Err.Raise
loc_00934BB1:   'Referenced from: 00934BA4
loc_00934BC3:   var_47C = var_47C + var_478 * 501
loc_00934BD7:   var_474 = var_474 + var_470 * 501
  loc_00934BF9: var_308 = var_308 - 0001h
loc_00934C06:   var_47C = var_308
loc_00934C16:   If var_47C >= 501 Then GoTo loc_00934C21
loc_00934C1F:   GoTo loc_00934C2C
loc_00934C21:   'Referenced from: 00934C16
loc_00934C21:   var_eax = Err.Raise
loc_00934C26:   var_87C = Err.Raise
loc_00934C2C:   'Referenced from: 00934C1F
  loc_00934C33: var_190 = var_190 + 0001h
loc_00934C40:   var_478 = var_190
loc_00934C50:   If var_478 >= 501 Then GoTo loc_00934C5B
loc_00934C59:   GoTo loc_00934C66
loc_00934C5B:   'Referenced from: 00934C50
loc_00934C5B:   var_eax = Err.Raise
loc_00934C60:   var_880 = Err.Raise
loc_00934C66:   'Referenced from: 00934C59
loc_00934C6D:   var_474 = var_308
loc_00934C7D:   If var_474 >= 501 Then GoTo loc_00934C88
loc_00934C86:   GoTo loc_00934C93
loc_00934C88:   'Referenced from: 00934C7D
loc_00934C88:   var_eax = Err.Raise
loc_00934C8D:   var_884 = Err.Raise
loc_00934C93:   'Referenced from: 00934C86
  loc_00934C9A: var_190 = var_190 + 0001h
loc_00934CA7:   var_470 = var_190
loc_00934CB7:   If var_470 >= 501 Then GoTo loc_00934CC2
loc_00934CC0:   GoTo loc_00934CCD
loc_00934CC2:   'Referenced from: 00934CB7
loc_00934CC2:   var_eax = Err.Raise
loc_00934CC7:   var_888 = Err.Raise
loc_00934CCD:   'Referenced from: 00934CC0
loc_00934CDF:   var_47C = var_47C + var_478 * 501
loc_00934CF3:   var_474 = var_474 + var_470 * 501
  loc_00934D15: var_308 = var_308 - 0001h
loc_00934D22:   var_47C = var_308
loc_00934D32:   If var_47C >= 501 Then GoTo loc_00934D3D
loc_00934D3B:   GoTo loc_00934D48
loc_00934D3D:   'Referenced from: 00934D32
loc_00934D3D:   var_eax = Err.Raise
loc_00934D42:   var_88C = Err.Raise
loc_00934D48:   'Referenced from: 00934D3B
  loc_00934D4F: var_190 = var_190 + 0002h
loc_00934D5C:   var_478 = var_190
loc_00934D6C:   If var_478 >= 501 Then GoTo loc_00934D77
loc_00934D75:   GoTo loc_00934D82
loc_00934D77:   'Referenced from: 00934D6C
loc_00934D77:   var_eax = Err.Raise
loc_00934D7C:   var_890 = Err.Raise
loc_00934D82:   'Referenced from: 00934D75
loc_00934D89:   var_474 = var_308
loc_00934D99:   If var_474 >= 501 Then GoTo loc_00934DA4
loc_00934DA2:   GoTo loc_00934DAF
loc_00934DA4:   'Referenced from: 00934D99
loc_00934DA4:   var_eax = Err.Raise
loc_00934DA9:   var_894 = Err.Raise
loc_00934DAF:   'Referenced from: 00934DA2
  loc_00934DB6: var_190 = var_190 + 0002h
loc_00934DC3:   var_470 = var_190
loc_00934DD3:   If var_470 >= 501 Then GoTo loc_00934DDE
loc_00934DDC:   GoTo loc_00934DE9
loc_00934DDE:   'Referenced from: 00934DD3
loc_00934DDE:   var_eax = Err.Raise
loc_00934DE3:   var_898 = Err.Raise
loc_00934DE9:   'Referenced from: 00934DDC
loc_00934DFB:   var_47C = var_47C + var_478 * 501
loc_00934E0F:   var_474 = var_474 + var_470 * 501
loc_00934E2A:   GoTo loc_00934ABA
loc_00934E2F:   'Referenced from: 00934A3E
loc_00934E3D:   var_474 = var_2B8
loc_00934E4D:   If var_474 >= 501 Then GoTo loc_00934E58
loc_00934E56:   GoTo loc_00934E63
loc_00934E58:   'Referenced from: 00934E4D
loc_00934E58:   var_eax = Err.Raise
loc_00934E5D:   var_89C = Err.Raise
loc_00934E63:   'Referenced from: 00934E56
loc_00934E6A:   var_470 = var_190
loc_00934E7A:   If var_470 >= 501 Then GoTo loc_00934E85
loc_00934E83:   GoTo loc_00934E90
loc_00934E85:   'Referenced from: 00934E7A
loc_00934E85:   var_eax = Err.Raise
loc_00934E8A:   var_8A0 = Err.Raise
loc_00934E90:   'Referenced from: 00934E83
loc_00934EA2:   var_474 = var_474 + var_470 * 501
loc_00934EC1:   var_474 = var_2B8
loc_00934ED1:   If var_474 >= 501 Then GoTo loc_00934EDC
loc_00934EDA:   GoTo loc_00934EE7
loc_00934EDC:   'Referenced from: 00934ED1
loc_00934EDC:   var_eax = Err.Raise
loc_00934EE1:   var_8A4 = Err.Raise
loc_00934EE7:   'Referenced from: 00934EDA
  loc_00934EEE: var_190 = var_190 + 0001h
loc_00934EFB:   var_470 = var_190
loc_00934F0B:   If var_470 >= 501 Then GoTo loc_00934F16
loc_00934F14:   GoTo loc_00934F21
loc_00934F16:   'Referenced from: 00934F0B
loc_00934F16:   var_eax = Err.Raise
loc_00934F1B:   var_8A8 = Err.Raise
loc_00934F21:   'Referenced from: 00934F14
loc_00934F33:   var_474 = var_474 + var_470 * 501
  loc_00934F4F: var_44 = var_44 + 0001h
loc_00934F59:   var_44 = var_44
loc_00934F6B:   var_474 = var_2B8
loc_00934F7B:   If var_474 >= 501 Then GoTo loc_00934F86
loc_00934F84:   GoTo loc_00934F91
loc_00934F86:   'Referenced from: 00934F7B
loc_00934F86:   var_eax = Err.Raise
loc_00934F8B:   var_8AC = Err.Raise
loc_00934F91:   'Referenced from: 00934F84
  loc_00934F98: var_190 = var_190 + 0002h
loc_00934FA5:   var_470 = var_190
loc_00934FB5:   If var_470 >= 501 Then GoTo loc_00934FC0
loc_00934FBE:   GoTo loc_00934FCB
loc_00934FC0:   'Referenced from: 00934FB5
loc_00934FC0:   var_eax = Err.Raise
loc_00934FC5:   var_8B0 = Err.Raise
loc_00934FCB:   'Referenced from: 00934FBE
loc_00934FE1:   var_474 = var_474 + var_470 * 501
loc_00934FFA:   var_474 = var_280
loc_0093500A:   If var_474 >= 501 Then GoTo loc_00935015
loc_00935013:   GoTo loc_00935020
loc_00935015:   'Referenced from: 0093500A
loc_00935015:   var_eax = Err.Raise
loc_0093501A:   var_8B4 = Err.Raise
loc_00935020:   'Referenced from: 00935013
loc_00935027:   var_470 = var_280
loc_00935037:   If var_470 >= 501 Then GoTo loc_00935042
loc_00935040:   GoTo loc_0093504D
loc_00935042:   'Referenced from: 00935037
loc_00935042:   var_eax = Err.Raise
loc_00935047:   var_8B8 = Err.Raise
loc_0093504D:   'Referenced from: 00935040
  loc_0093505D: ecx+eax*2 = ecx+eax*2 + 0001h
  loc_00935084: On Error Goto
  loc_00935097: var_8BC = On Error Goto
loc_009350A4:   If var_8BC = 1 Then GoTo loc_009350B3
loc_009350AD:   If var_8BC = 2 Then GoTo loc_009350B1
loc_009350AF:   GoTo loc_009350B8
loc_009350B1:   'Referenced from: 009350AD
loc_009350B1:   GoTo loc_009350B8
loc_009350B3:   'Referenced from: 009350A4
loc_009350B3:   GoTo loc_009392EA
loc_009350B8:   'Referenced from: 009350AF
  loc_009350F5: var_eax = Unknown_VTable_Call[eax+000000E0h]
  loc_009350FD: var_474 = Unknown_VTable_Call[eax+000000E0h]
loc_00935140:   setz al
loc_00935160:   If var_478 = 0 Then GoTo loc_009369C1
loc_00935199:   If (var_304 = 1) = 0 Then GoTo loc_0093565D
  loc_009351BB: var_eax = Unknown_VTable_Call[eax+0000020Ch]
  loc_009351C3: var_470 = Unknown_VTable_Call[eax+0000020Ch]
loc_009352C7:   var_478 = frmOutTwo.lblLocation.VtFont
  loc_00935308: call __vbaCastObj(var_32C, var_006EA910, var_3A4, var_3A0, var_39C, var_470, var_42C, var_328, var_478, Me, var_14C, var_4037A0, var_4037A4, var_4026C0)
  loc_0093534C: 1033 = frmOutTwo.lblLocation.VtFont
loc_00935351:   var_470 = eax
loc_009353B6:   var_3E0 = "Order"
  loc_009353DF: var_eax = Unknown_VTable_Call[eax+000000D0h]
  loc_009353E7: var_470 = Unknown_VTable_Call[eax+000000D0h]
loc_009354A8:   var_3E0 = "First Value"
  loc_009354D1: var_eax = Unknown_VTable_Call[eax+000000D0h]
  loc_009354D9: var_470 = Unknown_VTable_Call[eax+000000D0h]
loc_0093559A:   var_3E0 = "Second Value"
  loc_009355C3: var_eax = Unknown_VTable_Call[eax+000000D0h]
  loc_009355CB: var_470 = Unknown_VTable_Call[eax+000000D0h]
loc_0093565D:   'Referenced from: 00935199
loc_0093569A:   var_304 = var_304 + 1
loc_009356C7:   var_2B4 = var_44
loc_009356DA:   var_474 = var_2B8
loc_009356EA:   If var_474 >= 501 Then GoTo loc_009356F5
loc_009356F3:   GoTo loc_00935700
loc_009356F5:   'Referenced from: 009356EA
loc_009356F5:   var_eax = Err.Raise
loc_009356FA:   var_8DC = Err.Raise
loc_00935700:   'Referenced from: 009356F3
loc_00935707:   var_470 = var_190
loc_00935717:   If var_470 >= 501 Then GoTo loc_00935722
loc_00935720:   GoTo loc_0093572D
loc_00935722:   'Referenced from: 00935717
loc_00935722:   var_eax = Err.Raise
loc_00935727:   var_8E0 = Err.Raise
loc_0093572D:   'Referenced from: 00935720
loc_0093573F:   var_474 = var_474 + var_470 * 501
loc_00935763:   var_38 = eax + ecx * 4
loc_00935776:   var_474 = var_2B8
loc_00935786:   If var_474 >= 501 Then GoTo loc_00935791
loc_0093578F:   GoTo loc_0093579C
loc_00935791:   'Referenced from: 00935786
loc_00935791:   var_eax = Err.Raise
loc_00935796:   var_8E4 = Err.Raise
loc_0093579C:   'Referenced from: 0093578F
  loc_009357A3: var_190 = var_190 + 0001h
loc_009357B0:   var_470 = var_190
loc_009357C0:   If var_470 >= 501 Then GoTo loc_009357CB
loc_009357C9:   GoTo loc_009357D6
loc_009357CB:   'Referenced from: 009357C0
loc_009357CB:   var_eax = Err.Raise
loc_009357D0:   var_8E8 = Err.Raise
loc_009357D6:   'Referenced from: 009357C9
loc_009357E8:   var_474 = var_474 + var_470 * 501
loc_0093580F:   var_148 = eax + ecx * 4
loc_0093587C:   var_3A0 = var_304
loc_009358A6:   var_3D0 = Format$(var_2B4, "#####0")
  loc_009358CB: var_eax = Unknown_VTable_Call[eax+000000D0h]
  loc_009358D3: var_470 = Unknown_VTable_Call[eax+000000D0h]
loc_009359CA:   var_3A0 = var_304
loc_009359F4:   var_3D0 = Format$(var_38, "#####0")
  loc_00935A19: var_eax = Unknown_VTable_Call[eax+000000D0h]
  loc_00935A21: var_470 = Unknown_VTable_Call[eax+000000D0h]
loc_00935B1B:   var_3A0 = var_304
loc_00935B45:   var_3D0 = Format$(var_148, "#####0")
  loc_00935B6A: var_eax = Unknown_VTable_Call[eax+000000D0h]
  loc_00935B72: var_470 = Unknown_VTable_Call[eax+000000D0h]
  loc_00935C55: var_eax = Unknown_VTable_Call[eax+000000A0h]
  loc_00935C5D: var_474 = Unknown_VTable_Call[eax+000000A0h]
loc_00935CD8:   var_478 = (var_304 - 1 = var_31C)
loc_00935CFE:   If var_478 = 0 Then GoTo loc_009369C1
  loc_00935D84: var_eax = Unknown_VTable_Call[eax+00000058h]
  loc_00935D89: var_474 = Unknown_VTable_Call[eax+00000058h]
  loc_00935E79: var_eax = Unknown_VTable_Call[eax+00000058h]
  loc_00935E7E: var_47C = Unknown_VTable_Call[eax+00000058h]
  loc_00935F6E: var_eax = Unknown_VTable_Call[eax+000000A0h]
  loc_00935F76: var_484 = Unknown_VTable_Call[eax+000000A0h]
  loc_0093606C: var_eax = Unknown_VTable_Call[eax+000000B0h]
  loc_00936074: var_474 = Unknown_VTable_Call[eax+000000B0h]
  loc_0093614A: var_eax = Unknown_VTable_Call[eax+000000B0h]
  loc_00936152: var_474 = Unknown_VTable_Call[eax+000000B0h]
  loc_009361B8: var_348 = var_328."Font"
  loc_009361C1: call __vbaVarLateMemSt(var_348, var_3A0, var_39C, var_3A4, var_3A0, var_39C)
  loc_0093625C: var_eax = Unknown_VTable_Call[eax+00000058h]
  loc_00936261: var_474 = Unknown_VTable_Call[eax+00000058h]
loc_009362DE:   var_3E0 = var_304
  loc_00936353: var_eax = Unknown_VTable_Call[eax+00000058h]
  loc_00936358: var_47C = Unknown_VTable_Call[eax+00000058h]
  loc_00936448: var_eax = Unknown_VTable_Call[eax+000000A0h]
  loc_00936450: var_484 = Unknown_VTable_Call[eax+000000A0h]
  loc_00936546: var_eax = Unknown_VTable_Call[eax+000000B0h]
  loc_0093654E: var_474 = Unknown_VTable_Call[eax+000000B0h]
  loc_009365D0: var_eax = Unknown_VTable_Call[eax+0000004Ch]
  loc_009365D5: var_470 = Unknown_VTable_Call[eax+0000004Ch]
  loc_009366A1: var_eax = Unknown_VTable_Call[eax+00000058h]
  loc_009366A6: var_474 = Unknown_VTable_Call[eax+00000058h]
  loc_00936737: call __vbaVarLateMemSt(var_348)
  loc_009367E8: var_eax = Unknown_VTable_Call[eax+00000058h]
  loc_009367ED: var_474 = Unknown_VTable_Call[eax+00000058h]
  loc_0093687E: call __vbaVarLateMemSt(var_348)
  loc_00936919: var_eax = Unknown_VTable_Call[eax+00000058h]
  loc_0093691E: var_474 = Unknown_VTable_Call[eax+00000058h]
  loc_009369A3: var_358 = Me.
loc_009369C1:   'Referenced from: 00935160
  loc_009369FE: var_eax = Unknown_VTable_Call[eax+000000E0h]
  loc_00936A06: var_474 = Unknown_VTable_Call[eax+000000E0h]
loc_00936A49:   setz al
loc_00936A69:   If var_478 = 0 Then GoTo loc_00937B5E
loc_00936ADC:   var_3A0 = var_EE0124 & "-Spares"
  loc_00936B51: var_eax = Unknown_VTable_Call[eax+0000006Ch]
  loc_00936B56: var_470 = Unknown_VTable_Call[eax+0000006Ch]
loc_00936B92:   var_56C = var_328
loc_00936BDD:   var_3A0 = "Order"
  loc_00936C3C: var_eax = Unknown_VTable_Call[eax+00000070h]
  loc_00936C41: var_470 = Unknown_VTable_Call[eax+00000070h]
loc_00936C7A:   var_570 = var_328
  loc_00936CAF: var_eax = Unknown_VTable_Call[eax+00000060h]
  loc_00936CB4: var_470 = Unknown_VTable_Call[eax+00000060h]
loc_00936D00:   Set var_32C = var_318
loc_00936D19:   var_478 = frmOutTwo.Label6.VtFont
loc_00936D96:   var_3A0 = "First-Value"
  loc_00936DF5: var_eax = Unknown_VTable_Call[eax+00000070h]
  loc_00936DFA: var_470 = Unknown_VTable_Call[eax+00000070h]
loc_00936E33:   var_574 = var_328
  loc_00936E68: var_eax = Unknown_VTable_Call[eax+00000060h]
  loc_00936E6D: var_470 = Unknown_VTable_Call[eax+00000060h]
loc_00936EB9:   Set var_32C = var_318
loc_00936ED2:   var_478 = frmOutTwo.Label6.VtFont
loc_00936F4F:   var_3A0 = "Second-Value"
  loc_00936FAE: var_eax = Unknown_VTable_Call[eax+00000070h]
  loc_00936FB3: var_470 = Unknown_VTable_Call[eax+00000070h]
loc_00936FEC:   var_578 = var_328
  loc_00937021: var_eax = Unknown_VTable_Call[eax+00000060h]
  loc_00937026: var_470 = Unknown_VTable_Call[eax+00000060h]
loc_00937072:   Set var_32C = var_318
loc_0093708B:   var_478 = frmOutTwo.Label6.VtFont
loc_009370E2:   On Error Resume Next
loc_00937103:   frmOutTwo.Label6.Font = var_328
loc_00937108:   var_470 = eax
loc_00937163:   var_478 = frmOutTwo.Label6.Auto
loc_009371C0:   frmOutTwo.Label6.Font = var_328
loc_009371C5:   var_470 = eax
loc_00937211:   Set var_32C = var_70
loc_00937225:   var_32C = frmOutTwo.Label6.VtFont
loc_0093722A:   var_478 = var_32C
  loc_00937312: var_eax = Unknown_VTable_Call[eax+000000BCh]
  loc_0093731A: var_470 = Unknown_VTable_Call[eax+000000BCh]
loc_00937359:   var_57C = var_328
  loc_0093738D: var_eax = Unknown_VTable_Call[eax+000000C0h]
  loc_00937395: var_470 = Unknown_VTable_Call[eax+000000C0h]
loc_009373F6:   var_2B4 = var_44
loc_00937409:   var_474 = var_2B8
loc_00937419:   If var_474 >= 501 Then GoTo loc_00937424
loc_00937422:   GoTo loc_0093742F
loc_00937424:   'Referenced from: 00937419
loc_00937424:   var_eax = Err.Raise
loc_00937429:   var_9A4 = Err.Raise
loc_0093742F:   'Referenced from: 00937422
loc_00937436:   var_470 = var_190
loc_00937446:   If var_470 >= 501 Then GoTo loc_00937451
loc_0093744F:   GoTo loc_0093745C
loc_00937451:   'Referenced from: 00937446
loc_00937451:   var_eax = Err.Raise
loc_00937456:   var_9A8 = Err.Raise
loc_0093745C:   'Referenced from: 0093744F
loc_0093746E:   var_474 = var_474 + var_470 * 501
loc_00937492:   var_38 = eax + ecx * 4
loc_009374A5:   var_474 = var_2B8
loc_009374B5:   If var_474 >= 501 Then GoTo loc_009374C0
loc_009374BE:   GoTo loc_009374CB
loc_009374C0:   'Referenced from: 009374B5
loc_009374C0:   var_eax = Err.Raise
loc_009374C5:   var_9AC = Err.Raise
loc_009374CB:   'Referenced from: 009374BE
  loc_009374D2: var_190 = var_190 + 0001h
loc_009374DF:   var_470 = var_190
loc_009374EF:   If var_470 >= 501 Then GoTo loc_009374FA
loc_009374F8:   GoTo loc_00937505
loc_009374FA:   'Referenced from: 009374EF
loc_009374FA:   var_eax = Err.Raise
loc_009374FF:   var_9B0 = Err.Raise
loc_00937505:   'Referenced from: 009374F8
loc_00937517:   var_474 = var_474 + var_470 * 501
loc_0093753E:   var_148 = eax + ecx * 4
loc_0093758E:   var_150 = Format$(var_2B4, "#####0")
loc_009375B0:   var_C0 = "Order"
  loc_009375D1: var_eax = Unknown_VTable_Call[eax+000000B4h]
  loc_009375D9: var_470 = Unknown_VTable_Call[eax+000000B4h]
loc_00937624:   var_3A0 = var_C0
loc_0093765D:   frmOutTwo.Label6.Auto = 8
loc_00937662:   var_478 = eax
loc_009376AA:   var_3B0 = var_150
loc_009376E1:   var_480 = frmOutTwo.Label6.Font
loc_00937777:   var_150 = Format$(var_38, "#####0")
loc_00937799:   var_C0 = "First-Value"
  loc_009377BA: var_eax = Unknown_VTable_Call[eax+000000B4h]
  loc_009377C2: var_470 = Unknown_VTable_Call[eax+000000B4h]
loc_0093780D:   var_3A0 = var_C0
  loc_00937846: var_eax = Unknown_VTable_Call[eax+00000030h]
  loc_0093784B: var_478 = Unknown_VTable_Call[eax+00000030h]
loc_00937893:   var_3B0 = var_150
  loc_009378C5: var_eax = Unknown_VTable_Call[eax+00000048h]
  loc_009378CA: var_480 = Unknown_VTable_Call[eax+00000048h]
loc_00937963:   var_150 = Format$(var_148, "#####0")
loc_00937985:   var_C0 = "Second-Value"
  loc_009379A6: var_eax = Unknown_VTable_Call[eax+000000B4h]
  loc_009379AE: var_470 = Unknown_VTable_Call[eax+000000B4h]
loc_009379F9:   var_3A0 = var_C0
  loc_00937A32: var_eax = Unknown_VTable_Call[eax+00000030h]
  loc_00937A37: var_478 = Unknown_VTable_Call[eax+00000030h]
loc_00937A7F:   var_3B0 = var_150
  loc_00937AB1: var_eax = Unknown_VTable_Call[eax+00000048h]
  loc_00937AB6: var_480 = Unknown_VTable_Call[eax+00000048h]
  loc_00937B1D: var_eax = Unknown_VTable_Call[eax+00000164h]
  loc_00937B25: var_470 = Unknown_VTable_Call[eax+00000164h]
  loc_00937B9B: var_eax = Unknown_VTable_Call[eax+000000E0h]
  loc_00937BA3: var_474 = Unknown_VTable_Call[eax+000000E0h]
loc_00937BE6:   setz al
loc_00937C06:   If var_478 = 0 Then GoTo loc_00937EE3
loc_00937C34:   var_2B4 = var_44
loc_00937C47:   var_474 = var_2B8
loc_00937C57:   If var_474 >= 501 Then GoTo loc_00937C62
loc_00937C60:   GoTo loc_00937C6D
loc_00937C62:   'Referenced from: 00937C57
loc_00937C62:   var_eax = Err.Raise
loc_00937C67:   var_9E0 = Err.Raise
loc_00937C6D:   'Referenced from: 00937C60
loc_00937C74:   var_470 = var_190
loc_00937C84:   If var_470 >= 501 Then GoTo loc_00937C8F
loc_00937C8D:   GoTo loc_00937C9A
loc_00937C8F:   'Referenced from: 00937C84
loc_00937C8F:   var_eax = Err.Raise
loc_00937C94:   var_9E4 = Err.Raise
loc_00937C9A:   'Referenced from: 00937C8D
loc_00937CAC:   var_474 = var_474 + var_470 * 501
loc_00937CD0:   var_38 = eax + ecx * 4
loc_00937CE3:   var_474 = var_2B8
loc_00937CF3:   If var_474 >= 501 Then GoTo loc_00937CFE
loc_00937CFC:   GoTo loc_00937D09
loc_00937CFE:   'Referenced from: 00937CF3
loc_00937CFE:   var_eax = Err.Raise
loc_00937D03:   var_9E8 = Err.Raise
loc_00937D09:   'Referenced from: 00937CFC
  loc_00937D10: var_190 = var_190 + 0001h
loc_00937D1D:   var_470 = var_190
loc_00937D2D:   If var_470 >= 501 Then GoTo loc_00937D38
loc_00937D36:   GoTo loc_00937D43
loc_00937D38:   'Referenced from: 00937D2D
loc_00937D38:   var_eax = Err.Raise
loc_00937D3D:   var_9EC = Err.Raise
loc_00937D43:   'Referenced from: 00937D36
loc_00937D55:   var_474 = var_474 + var_470 * 501
loc_00937DF0:   Print 4, Format$(var_2B4, "0000")
loc_00937E64:   Print 4, Format$(var_38, "0000000000")
loc_00937EDB:   Print 4, Format$(eax + ecx * 4, "0000000000")
loc_00937EE3:   'Referenced from: 00937C06
  loc_00937EF1: var_238 = var_238 + 0001h
loc_00937EFB:   var_238 = var_238
loc_00937F10:   var_470 = var_238
loc_00937F1D:   If var_470 >= 7 Then GoTo loc_00937F28
loc_00937F26:   GoTo loc_00937F33
loc_00937F28:   'Referenced from: 00937F1D
loc_00937F28:   var_eax = Err.Raise
loc_00937F2D:   var_9F0 = Err.Raise
loc_00937F33:   'Referenced from: 00937F26
  loc_00937F54: var_238 = var_238 + 0001h
loc_00937F5E:   var_238 = var_238
loc_00937F73:   var_478 = var_2B8
loc_00937F83:   If var_478 >= 501 Then GoTo loc_00937F8E
loc_00937F8C:   GoTo loc_00937F99
loc_00937F8E:   'Referenced from: 00937F83
loc_00937F8E:   var_eax = Err.Raise
loc_00937F93:   var_9F4 = Err.Raise
loc_00937F99:   'Referenced from: 00937F8C
loc_00937FA0:   var_474 = var_190
loc_00937FB0:   If var_474 >= 501 Then GoTo loc_00937FBB
loc_00937FB9:   GoTo loc_00937FC6
loc_00937FBB:   'Referenced from: 00937FB0
loc_00937FBB:   var_eax = Err.Raise
loc_00937FC0:   var_9F8 = Err.Raise
loc_00937FC6:   'Referenced from: 00937FB9
loc_00937FCD:   var_470 = var_238
loc_00937FDA:   If var_470 >= 7 Then GoTo loc_00937FE5
loc_00937FE3:   GoTo loc_00937FF0
loc_00937FE5:   'Referenced from: 00937FDA
loc_00937FE5:   var_eax = Err.Raise
loc_00937FEA:   var_9FC = Err.Raise
loc_00937FF0:   'Referenced from: 00937FE3
loc_00938002:   var_478 = var_478 + var_474 * 501
  loc_0093802A: var_238 = var_238 + 0001h
loc_00938034:   var_238 = var_238
loc_00938049:   var_478 = var_2B8
loc_00938059:   If var_478 >= 501 Then GoTo loc_00938064
loc_00938062:   GoTo loc_0093806F
loc_00938064:   'Referenced from: 00938059
loc_00938064:   var_eax = Err.Raise
loc_00938069:   var_A00 = Err.Raise
loc_0093806F:   'Referenced from: 00938062
  loc_00938083: var_474 = var_190 + 0001h
loc_00938093:   If var_474 >= 501 Then GoTo loc_0093809E
loc_0093809C:   GoTo loc_009380A9
loc_0093809E:   'Referenced from: 00938093
loc_0093809E:   var_eax = Err.Raise
loc_009380A3:   var_A04 = Err.Raise
loc_009380A9:   'Referenced from: 0093809C
loc_009380B0:   var_470 = var_238
loc_009380BD:   If var_470 >= 7 Then GoTo loc_009380C8
loc_009380C6:   GoTo loc_009380D3
loc_009380C8:   'Referenced from: 009380BD
loc_009380C8:   var_eax = Err.Raise
loc_009380CD:   var_A08 = Err.Raise
loc_009380D3:   'Referenced from: 009380C6
loc_009380E5:   var_478 = var_478 + var_474 * 501
  loc_0093813C: var_eax = Unknown_VTable_Call[eax+000000E0h]
  loc_00938144: var_474 = Unknown_VTable_Call[eax+000000E0h]
loc_00938187:   setz al
loc_009381A7:   If var_478 = 0 Then GoTo loc_009381AE
loc_009381A9:   GoTo loc_009385FF
loc_009381AE:   'Referenced from: 009381A7
loc_009381D5:   var_348 = "####0"
  loc_009381E1: var_238 = var_238 - 0002h
loc_009381EE:   var_470 = var_238
loc_009381FB:   If var_470 >= 7 Then GoTo loc_00938206
loc_00938204:   GoTo loc_00938211
loc_00938206:   'Referenced from: 009381FB
loc_00938206:   var_eax = Err.Raise
loc_0093820B:   var_A10 = Err.Raise
loc_00938211:   'Referenced from: 00938204
loc_00938220:   var_3A0 = ecx + eax * 4
  loc_00938274: 00000006h = 00000006h - Len(Format$(ecx+eax*4, var_348))
loc_009382A2:   Print 3, 6; h
loc_009382D1:   var_348 = "##########0"
  loc_009382DD: var_238 = var_238 - 0001h
loc_009382EA:   var_470 = var_238
loc_009382F7:   If var_470 >= 7 Then GoTo loc_00938302
loc_00938300:   GoTo loc_0093830D
loc_00938302:   'Referenced from: 009382F7
loc_00938302:   var_eax = Err.Raise
loc_00938307:   var_A14 = Err.Raise
loc_0093830D:   'Referenced from: 00938300
loc_0093831C:   var_3A0 = ecx + eax * 4
  loc_00938370: 0000000Bh = 0000000Bh - Len(Format$(ecx+eax*4, var_348))
loc_0093839E:   Print 3, 0; Bh
loc_009383CD:   var_348 = "##########0"
loc_009383D9:   var_470 = var_238
loc_009383E6:   If var_470 >= 7 Then GoTo loc_009383F1
loc_009383EF:   GoTo loc_009383FC
loc_009383F1:   'Referenced from: 009383E6
loc_009383F1:   var_eax = Err.Raise
loc_009383F6:   var_A18 = Err.Raise
loc_009383FC:   'Referenced from: 009383EF
loc_0093840B:   var_3A0 = ecx + eax * 4
  loc_0093845F: 0000000Dh = 0000000Dh - Len(Format$(ecx+eax*4, var_348))
  loc_0093848D: Print 3, 0000000Dh
  loc_009384D2: var_eax = Unknown_VTable_Call[eax+000000E0h]
  loc_009384DA: var_474 = Unknown_VTable_Call[eax+000000E0h]
loc_0093851D:   setz al
loc_0093853D:   If var_478 = 0 Then GoTo loc_0093854E
loc_0093854E:   'Referenced from: 0093853D
  loc_0093858B: var_eax = Unknown_VTable_Call[eax+000000E0h]
  loc_00938593: var_474 = Unknown_VTable_Call[eax+000000E0h]
loc_009385D6:   setz al
loc_009385F6:   If var_478 = 0 Then GoTo loc_009385FA
loc_009385F8:   GoTo loc_009385FF
loc_009385FA:   'Referenced from: 009385F6
loc_009385FA:   GoTo loc_009392EA
loc_009385FF:   'Referenced from: 009381A9
  loc_0093863C: var_eax = Unknown_VTable_Call[eax+000000E0h]
  loc_00938644: var_474 = Unknown_VTable_Call[eax+000000E0h]
loc_00938687:   setz al
loc_009386A7:   If var_478 = 0 Then GoTo loc_009386AE
loc_009386A9:   GoTo loc_009392EA
loc_009386AE:   'Referenced from: 009386A7
  loc_009386BB: 00EE085Ch = 00EE085Ch + 00EE085Eh
loc_009386CC:   If var_44 <> var_EE085C Then GoTo loc_009386D0
loc_009386CE:   GoTo loc_009386E6
loc_009386D0:   'Referenced from: 009386CC
loc_009386DF:   If var_238 >= 5 Then GoTo loc_009386E6
loc_009386E1:   GoTo loc_009392EA
loc_009386E6:   'Referenced from: 009386CE
loc_00938723:   var_470 = eax
  loc_0093873E: var_328 = Global.Printer
loc_00938743:   var_474 = var_328
  loc_0093878B: call __vbaPrintObj(var_006EA3B8, var_328, 00000003h, var_006EAC14, var_470, var_42C, var_328, var_474, Me, var_470, var_42C, var_328, var_474, Me, var_470, var_42C)
loc_009387C5:   var_348 = "##,##0"
loc_009387DB:   If var_470 >= 7 Then GoTo loc_009387E6
loc_009387E4:   GoTo loc_009387F1
loc_009387E6:   'Referenced from: 009387DB
loc_009387E6:   var_eax = Err.Raise
loc_009387EB:   var_A30 = Err.Raise
loc_009387F1:   'Referenced from: 009387E4
loc_00938800:   var_3A0 = ecx + eax * 4
loc_0093882F:   var_150 = Format$(ecx + eax * 4, var_348)
  loc_00938854: 00000006h = 00000006h - Len(var_150)
  loc_009388C0: var_328 = Global.Printer
loc_009388C5:   var_474 = var_328
  loc_00938914: call __vbaPrintObj(var_006EAC1C, var_328, var_BC, var_150, 00000001h, 00000001h, 00000001h)
  loc_0093897F: var_328 = Global.Printer
loc_00938984:   var_474 = var_328
  loc_009389CC: call __vbaPrintObj(var_006E89EC, var_328, var_006EAC28, 00000001h)
loc_00938A06:   var_348 = "###,###,##0"
loc_00938A1C:   If var_470 >= 7 Then GoTo loc_00938A27
loc_00938A25:   GoTo loc_00938A32
loc_00938A27:   'Referenced from: 00938A1C
loc_00938A27:   var_eax = Err.Raise
loc_00938A2C:   var_A44 = Err.Raise
loc_00938A32:   'Referenced from: 00938A25
loc_00938A41:   var_3A0 = ecx + eax * 4
loc_00938A70:   var_150 = Format$(ecx + eax * 4, var_348)
  loc_00938A95: 0000000Bh = 0000000Bh - Len(var_150)
  loc_00938B01: var_328 = Global.Printer
loc_00938B06:   var_474 = var_328
  loc_00938B53: call __vbaPrintObj(var_006EABEC, var_328, var_BC, var_150, 00000001h, 00000001h)
loc_00938B8D:   var_348 = "###,###,##0"
loc_00938BA3:   If var_470 >= 7 Then GoTo loc_00938BAE
loc_00938BAC:   GoTo loc_00938BB9
loc_00938BAE:   'Referenced from: 00938BA3
loc_00938BAE:   var_eax = Err.Raise
loc_00938BB3:   var_A50 = Err.Raise
loc_00938BB9:   'Referenced from: 00938BAC
loc_00938BC8:   var_3A0 = ecx + eax * 4
loc_00938BF7:   var_150 = Format$(ecx + eax * 4, var_348)
  loc_00938C1C: 0000000Dh = 0000000Dh - Len(var_150)
  loc_00938C88: var_328 = Global.Printer
loc_00938C8D:   var_474 = var_328
  loc_00938CDA: call __vbaPrintObj(var_006EABEC, var_328, var_BC, var_150, 00000001h, 00000001h)
loc_00938CFC:   If var_238 >= 4 Then GoTo loc_00938D03
loc_00938CFE:   GoTo loc_009397DE
loc_00938D03:   'Referenced from: 00938CFC
loc_00938D2A:   var_348 = "##,##0"
loc_00938D40:   If var_470 >= 7 Then GoTo loc_00938D4B
loc_00938D49:   GoTo loc_00938D56
loc_00938D4B:   'Referenced from: 00938D40
loc_00938D4B:   var_eax = Err.Raise
loc_00938D50:   var_A5C = Err.Raise
loc_00938D56:   'Referenced from: 00938D49
loc_00938D65:   var_3A0 = ecx + eax * 4
loc_00938D94:   var_150 = Format$(ecx + eax * 4, var_348)
  loc_00938DB9: 0000000Ch = 0000000Ch - Len(var_150)
  loc_00938E25: var_328 = Global.Printer
loc_00938E2A:   var_474 = var_328
  loc_00938E79: call __vbaPrintObj(var_006EAC1C, var_328, var_BC, var_150, 00000001h, 00000001h, 00000001h)
  loc_00938EE4: var_328 = Global.Printer
loc_00938EE9:   var_474 = var_328
  loc_00938F31: call __vbaPrintObj(var_006E89EC, var_328, var_006EAC28, 00000001h)
loc_00938F6B:   var_348 = "###,###,##0"
loc_00938F81:   If var_470 >= 7 Then GoTo loc_00938F8C
loc_00938F8A:   GoTo loc_00938F97
loc_00938F8C:   'Referenced from: 00938F81
loc_00938F8C:   var_eax = Err.Raise
loc_00938F91:   var_A70 = Err.Raise
loc_00938F97:   'Referenced from: 00938F8A
loc_00938FA6:   var_3A0 = ecx + eax * 4
loc_00938FD5:   var_150 = Format$(ecx + eax * 4, var_348)
  loc_00938FFA: 0000000Bh = 0000000Bh - Len(var_150)
  loc_00939066: var_328 = Global.Printer
loc_0093906B:   var_474 = var_328
  loc_009390B8: call __vbaPrintObj(var_006EABEC, var_328, var_BC, var_150, 00000001h, 00000001h)
loc_009390F2:   var_348 = "###,###,##0"
loc_00939108:   If var_470 >= 7 Then GoTo loc_00939113
loc_00939111:   GoTo loc_0093911E
loc_00939113:   'Referenced from: 00939108
loc_00939113:   var_eax = Err.Raise
loc_00939118:   var_A7C = Err.Raise
loc_0093911E:   'Referenced from: 00939111
loc_0093912D:   var_3A0 = ecx + eax * 4
loc_0093915C:   var_150 = Format$(ecx + eax * 4, var_348)
  loc_00939181: 0000000Eh = 0000000Eh - Len(var_150)
  loc_009391ED: var_328 = Global.Printer
loc_009391F2:   var_474 = var_328
  loc_0093923F: call __vbaPrintObj(var_006EA3C4, var_328, var_BC, var_150, 00000001h, 00000001h)
  loc_0093925D: var_54 = var_54 + 0001h
loc_00939267:   var_54 = var_54
  loc_00939278: 00EE085Ch = 00EE085Ch + 00EE085Eh
loc_00939289:   If var_44 <> var_EE085C Then GoTo loc_0093928D
loc_0093928B:   GoTo loc_009392EA
loc_0093928D:   'Referenced from: 00939289
loc_009392AE:   If var_54 >= 0 Then GoTo loc_009392B2
loc_009392B0:   GoTo loc_009392EA
loc_009392B2:   'Referenced from: 009392AE
  loc_009392C0: var_eax = GoSub var_518
  loc_009392C7: If GoSub var_518 <> 0 Then GoTo loc_009392CE
loc_009392C9:   GoTo loc_00944A80
loc_009392CE:   'Referenced from: 009392C7
  loc_009392DC: var_eax = GoSub var_518
  loc_009392E3: If GoSub var_518 <> 0 Then GoTo loc_009392EA
loc_009392E5:   GoTo loc_00943610
loc_009392EA:   'Referenced from: 009350B3
  loc_00939327: var_eax = Unknown_VTable_Call[eax+000000E0h]
  loc_0093932F: var_474 = Unknown_VTable_Call[eax+000000E0h]
loc_00939372:   setz al
loc_00939392:   If var_478 = 0 Then GoTo loc_009393A3
loc_009393A3:   'Referenced from: 00939392
loc_009393AA:   GoTo loc_0093400D
loc_009393AF:   'Referenced from: 00934036
loc_009393BE:   If var_14C <> 2 Then GoTo loc_009393C5
loc_009393C0:   GoTo loc_009397DE
loc_009393C5:   'Referenced from: 009393BE
loc_009393D4:   var_28 = "OFF"
loc_009393E8:   var_24 = "OFF"
  loc_0093942A: var_eax = Unknown_VTable_Call[eax+000000E0h]
  loc_00939432: var_474 = Unknown_VTable_Call[eax+000000E0h]
loc_00939475:   setz al
loc_00939495:   If var_478 = 0 Then GoTo loc_009394B3
  loc_009394A5: var_eax = GoSub var_518
  loc_009394AC: If GoSub var_518 <> 0 Then GoTo loc_009394B3
loc_009394AE:   GoTo loc_00939800
loc_009394B3:   'Referenced from: 00939495
  loc_009394F0: var_eax = Unknown_VTable_Call[eax+000000E0h]
  loc_009394F8: var_474 = Unknown_VTable_Call[eax+000000E0h]
loc_0093953B:   setz al
loc_0093955B:   If var_478 = 0 Then GoTo loc_00939579
  loc_0093956B: var_eax = GoSub var_518
  loc_00939572: If GoSub var_518 <> 0 Then GoTo loc_00939579
loc_00939574:   GoTo loc_0093A794
loc_00939579:   'Referenced from: 0093955B
  loc_009395B6: var_eax = Unknown_VTable_Call[eax+000000E0h]
  loc_009395BE: var_474 = Unknown_VTable_Call[eax+000000E0h]
loc_00939601:   setz al
loc_00939621:   If var_478 = 0 Then GoTo loc_0093963F
  loc_00939631: var_eax = GoSub var_518
  loc_00939638: If GoSub var_518 <> 0 Then GoTo loc_0093963F
loc_0093963A:   GoTo loc_0093B955
loc_0093963F:   'Referenced from: 00939621
  loc_0093967C: var_eax = Unknown_VTable_Call[eax+000000E0h]
  loc_00939684: var_474 = Unknown_VTable_Call[eax+000000E0h]
loc_009396C7:   setz al
loc_009396E7:   If var_478 = 0 Then GoTo loc_00939705
  loc_009396F7: var_eax = GoSub var_518
  loc_009396FE: If GoSub var_518 <> 0 Then GoTo loc_00939705
loc_00939700:   GoTo loc_009400A3
loc_00939705:   'Referenced from: 009396E7
loc_00939727:   var_470 = var_328
  loc_00939742: var_eax = Unknown_VTable_Call[eax+000000E0h]
  loc_0093974A: var_474 = Unknown_VTable_Call[eax+000000E0h]
loc_0093978D:   setz al
loc_009397AD:   If var_478 = 0 Then GoTo loc_009397CB
  loc_009397BD: var_eax = GoSub var_518
  loc_009397C4: If GoSub var_518 <> 0 Then GoTo loc_009397CB
loc_009397C6:   GoTo loc_00942A09
loc_009397CB:   'Referenced from: 009397AD
  loc_009397D9: call Return(var_518, var_470, var_42C, var_328, var_518, Me, var_470, var_42C, var_328, var_518, Me, var_470, var_42C)
loc_009397DE:   'Referenced from: 00938CFE
  loc_009397FB: call Return(var_518)
loc_00939800:   'Referenced from: 009394AE
loc_00939822:   var_470 = var_328
  loc_0093983D: var_eax = Unknown_VTable_Call[eax+000000E0h]
  loc_00939845: var_474 = Unknown_VTable_Call[eax+000000E0h]
loc_00939888:   setz bl
loc_0093989E:   eax = (var_28 = "OFF") + 1
loc_009398AE:   setg al
loc_009398D1:   If var_478 = 0 Then GoTo loc_0093A004
  loc_00939903: 00000050h = 00000050h - Len("Windows RAT-STATS")
loc_00939953:   Print 3, CInt(var_470)
  loc_00939987: 00000050h = 00000050h - Len("Statistical Software")
loc_009399D7:   Print 3, CInt(Me)
loc_00939A81:   Print 3, "Date: " & Format$(Now, "m/d/yyyy")
loc_00939AD5:   Print 3, "Random Number Generator"
loc_00939B7D:   Print 3, "Time: " & Format$(Now, "h:mm")
  loc_00939BF5: 00000050h = 00000050h - Len("AUDIT: " & var_EE081C)
  loc_00939C2A: var_3C = CInt()
loc_00939C45:   Print 3, var_3C
loc_00939C60:   Print 3, vbNullString
loc_00939C7B:   Print 3, "SEED NUMBER: "
loc_00939CAF:   var_3A0 = vbNullString
loc_00939D06:   Print 3, Format$(vbNullString, "#####0.00")
loc_00939D23:   Print 3, 53
loc_00939D57:   var_3A0 = vbNullString
  loc_00939DAF: 0000000Fh = 0000000Fh - Len(Format$(vbNullString, "#,###,###,###"))
loc_00939DDD:   Print 3, 0; Fh
loc_00939DF3:   Print 3
loc_00939E08:   Print 3
loc_00939E28:   Print 3, "     FILE OF RANDOM NUMBERS: "
loc_00939E3E:   Print 3
loc_00939E58:   Print 3, "     TOTAL RANDOM NUMBERS GENERATED: "
  loc_00939E92: 00EE085Ch = 00EE085Ch + 00EE085Eh
loc_00939F00:   Print 3, Format$(15599708, "##,###")
loc_00939F16:   Print 3
loc_00939F30:   Print 3, "THE NUMBERS ARE IN THE FOLLOWING FORMAT IN YOUR FILE:"
loc_00939F4B:   Print 3, "   POSITIONS 1 THROUGH  6 - ORDER OF SELECTION"
loc_00939F66:   Print 3, "   POSITIONS 7 THROUGH 17 - FIRST NUMBER OF SET"
loc_00939F81:   Print 3, "   POSITIONS 18 THROUGH 30 - SECOND NUMBER OF SET"
loc_00939F9C:   Print 3, "EACH COLUMN OF NUMBERS IS RIGHT JUSTIFIED."
loc_00939FB2:   Print 3
loc_00939FC7:   Print 3
loc_00939FE1:   Print 3, "Selection   First       Second"
loc_00939FFC:   Print 3, "  Order    Number       Number"
loc_0093A004:   'Referenced from: 009398D1
  loc_0093A041: var_eax = Unknown_VTable_Call[eax+000000E0h]
  loc_0093A049: var_474 = Unknown_VTable_Call[eax+000000E0h]
loc_0093A08C:   setz al
loc_0093A0AC:   If var_478 = 0 Then GoTo loc_0093A0B3
loc_0093A0AE:   GoTo loc_0093A794
loc_0093A0B3:   'Referenced from: 0093A0AC
loc_0093A0C9:   If (var_28 <> "ON") <> 0 Then GoTo loc_0093A0D0
loc_0093A0CB:   GoTo loc_0093A794
loc_0093A0D0:   'Referenced from: 0093A0C9
loc_0093A0DF:   var_28 = "ON"
loc_0093A106:   GoTo loc_0093A123
loc_0093A108:
loc_0093A10F:   var_1E0 = var_1E0 + 1
loc_0093A11C:   var_1E0 = var_1E0
loc_0093A123:   'Referenced from: 0093A106
loc_0093A131:   If var_1E0 > 0 Then GoTo loc_0093A794
loc_0093A145:   var_470 = var_1E0
loc_0093A155:   If var_470 >= 501 Then GoTo loc_0093A160
loc_0093A15E:   GoTo loc_0093A16B
loc_0093A160:   'Referenced from: 0093A155
loc_0093A160:   var_eax = Err.Raise
loc_0093A165:   var_ACC = Err.Raise
loc_0093A16B:   'Referenced from: 0093A15E
loc_0093A17B:   var_4C8 = ecx + eax * 2
loc_0093A194:   GoTo loc_0093A1B1
loc_0093A196:
loc_0093A19D:   var_1B4 = var_1B4 + 1
loc_0093A1AA:   var_1B4 = var_1B4
loc_0093A1B1:   'Referenced from: 0093A194
loc_0093A1BF:   If var_1B4 > 0 Then GoTo loc_0093A788
  loc_0093A1D3: var_1E0 = var_1E0 * 0003h
  loc_0093A1E7: var_190 = var_1E0 - 0002h
  loc_0093A1FC: var_238 = var_238 + 0001h
loc_0093A206:   var_238 = var_238
  loc_0093A21B: var_2F4 = var_2F4 + 0001h
loc_0093A225:   var_2F4 = var_2F4
loc_0093A23A:   var_478 = var_1B4
loc_0093A24A:   If var_478 >= 501 Then GoTo loc_0093A255
loc_0093A253:   GoTo loc_0093A260
loc_0093A255:   'Referenced from: 0093A24A
loc_0093A255:   var_eax = Err.Raise
loc_0093A25A:   var_AD0 = Err.Raise
loc_0093A260:   'Referenced from: 0093A253
  loc_0093A267: var_474 = var_1E0 - 0002h - 0002h
loc_0093A277:   If var_474 >= 501 Then GoTo loc_0093A282
loc_0093A280:   GoTo loc_0093A28D
loc_0093A282:   'Referenced from: 0093A277
loc_0093A282:   var_eax = Err.Raise
loc_0093A287:   var_AD4 = Err.Raise
loc_0093A28D:   'Referenced from: 0093A280
loc_0093A294:   var_470 = var_238
loc_0093A2A1:   If var_470 >= 7 Then GoTo loc_0093A2AC
loc_0093A2AA:   GoTo loc_0093A2B7
loc_0093A2AC:   'Referenced from: 0093A2A1
loc_0093A2AC:   var_eax = Err.Raise
loc_0093A2B1:   var_AD8 = Err.Raise
loc_0093A2B7:   'Referenced from: 0093A2AA
loc_0093A2C9:   var_478 = var_478 + var_474 * 501
  loc_0093A2F1: var_238 = var_238 + 0001h
loc_0093A2FB:   var_238 = var_238
loc_0093A310:   var_478 = var_1B4
loc_0093A320:   If var_478 >= 501 Then GoTo loc_0093A32B
loc_0093A329:   GoTo loc_0093A336
loc_0093A32B:   'Referenced from: 0093A320
loc_0093A32B:   var_eax = Err.Raise
loc_0093A330:   var_ADC = Err.Raise
loc_0093A336:   'Referenced from: 0093A329
  loc_0093A33D: var_190 = var_190 + 0001h
  loc_0093A34A: var_474 = var_190 + 0001h
loc_0093A35A:   If var_474 >= 501 Then GoTo loc_0093A365
loc_0093A363:   GoTo loc_0093A370
loc_0093A365:   'Referenced from: 0093A35A
loc_0093A365:   var_eax = Err.Raise
loc_0093A36A:   var_AE0 = Err.Raise
loc_0093A370:   'Referenced from: 0093A363
loc_0093A377:   var_470 = var_238
loc_0093A384:   If var_470 >= 7 Then GoTo loc_0093A38F
loc_0093A38D:   GoTo loc_0093A39A
loc_0093A38F:   'Referenced from: 0093A384
loc_0093A38F:   var_eax = Err.Raise
loc_0093A394:   var_AE4 = Err.Raise
loc_0093A39A:   'Referenced from: 0093A38D
loc_0093A3AC:   var_478 = var_478 + var_474 * 501
  loc_0093A3D4: var_238 = var_238 + 0001h
loc_0093A3DE:   var_238 = var_238
loc_0093A3F3:   var_478 = var_1B4
loc_0093A403:   If var_478 >= 501 Then GoTo loc_0093A40E
loc_0093A40C:   GoTo loc_0093A419
loc_0093A40E:   'Referenced from: 0093A403
loc_0093A40E:   var_eax = Err.Raise
loc_0093A413:   var_AE8 = Err.Raise
loc_0093A419:   'Referenced from: 0093A40C
  loc_0093A42D: var_474 = var_190 + 0002h
loc_0093A43D:   If var_474 >= 501 Then GoTo loc_0093A448
loc_0093A446:   GoTo loc_0093A453
loc_0093A448:   'Referenced from: 0093A43D
loc_0093A448:   var_eax = Err.Raise
loc_0093A44D:   var_AEC = Err.Raise
loc_0093A453:   'Referenced from: 0093A446
loc_0093A45A:   var_470 = var_238
loc_0093A467:   If var_470 >= 7 Then GoTo loc_0093A472
loc_0093A470:   GoTo loc_0093A47D
loc_0093A472:   'Referenced from: 0093A467
loc_0093A472:   var_eax = Err.Raise
loc_0093A477:   var_AF0 = Err.Raise
loc_0093A47D:   'Referenced from: 0093A470
loc_0093A48F:   var_478 = var_478 + var_474 * 501
loc_0093A4D0:   var_348 = "#####0"
loc_0093A4E6:   If var_470 >= 7 Then GoTo loc_0093A4F1
loc_0093A4EF:   GoTo loc_0093A4FC
loc_0093A4F1:   'Referenced from: 0093A4E6
loc_0093A4F1:   var_eax = Err.Raise
loc_0093A4F6:   var_AF4 = Err.Raise
loc_0093A4FC:   'Referenced from: 0093A4EF
loc_0093A50B:   var_3A0 = ecx + eax * 4
  loc_0093A55F: 00000006h = 00000006h - Len(Format$(ecx+eax*4, var_348))
loc_0093A58D:   Print 3, 6; h
loc_0093A5BC:   var_348 = "###########0"
loc_0093A5D2:   If var_470 >= 7 Then GoTo loc_0093A5DD
loc_0093A5DB:   GoTo loc_0093A5E8
loc_0093A5DD:   'Referenced from: 0093A5D2
loc_0093A5DD:   var_eax = Err.Raise
loc_0093A5E2:   var_AF8 = Err.Raise
loc_0093A5E8:   'Referenced from: 0093A5DB
loc_0093A5F7:   var_3A0 = ecx + eax * 4
  loc_0093A64B: 0000000Bh = 0000000Bh - Len(Format$(ecx+eax*4, var_348))
loc_0093A679:   Print 3, 0; Bh
loc_0093A6A8:   var_348 = "###########0"
loc_0093A6BE:   If var_470 >= 7 Then GoTo loc_0093A6C9
loc_0093A6C7:   GoTo loc_0093A6D4
loc_0093A6C9:   'Referenced from: 0093A6BE
loc_0093A6C9:   var_eax = Err.Raise
loc_0093A6CE:   var_AFC = Err.Raise
loc_0093A6D4:   'Referenced from: 0093A6C7
loc_0093A6E3:   var_3A0 = ecx + eax * 4
  loc_0093A737: 0000000Dh = 0000000Dh - Len(Format$(ecx+eax*4, var_348))
  loc_0093A765: Print 3, 0000000Dh
loc_0093A783:   GoTo loc_0093A196
loc_0093A788:   'Referenced from: 0093A1BF
loc_0093A78F:   GoTo loc_0093A108
loc_0093A794:   'Referenced from: 00939574
loc_0093A7B6:   var_470 = var_328
  loc_0093A7D1: var_eax = Unknown_VTable_Call[eax+000000E0h]
  loc_0093A7D9: var_474 = Unknown_VTable_Call[eax+000000E0h]
loc_0093A81C:   setz al
loc_0093A83C:   If var_478 = 0 Then GoTo loc_0093A851
  loc_0093A84C: call Return(var_518, var_470, var_42C, var_328, var_518, Me, var_518, Me)
loc_0093A851:   'Referenced from: 0093A83C
loc_0093A867:   If (var_24 <> "ON") <> 0 Then GoTo loc_0093A87C
  loc_0093A877: call Return(var_518)
loc_0093A87C:   'Referenced from: 0093A867
loc_0093A8A9:   var_24 = "ON"
loc_0093A8D0:   GoTo loc_0093A8ED
loc_0093A8D2:
loc_0093A8D9:   var_1E0 = var_1E0 + 1
loc_0093A8E6:   var_1E0 = var_1E0
loc_0093A8ED:   'Referenced from: 0093A8D0
loc_0093A8FB:   If var_1E0 > 0 Then GoTo loc_0093B8F3
loc_0093A90F:   var_470 = var_1E0
loc_0093A91F:   If var_470 >= 501 Then GoTo loc_0093A92A
loc_0093A928:   GoTo loc_0093A935
loc_0093A92A:   'Referenced from: 0093A91F
loc_0093A92A:   var_eax = Err.Raise
loc_0093A92F:   var_B04 = Err.Raise
loc_0093A935:   'Referenced from: 0093A928
loc_0093A945:   var_4D8 = ecx + eax * 2
loc_0093A95E:   GoTo loc_0093A97B
loc_0093A960:
loc_0093A967:   var_1B4 = var_1B4 + 1
loc_0093A974:   var_1B4 = var_1B4
loc_0093A97B:   'Referenced from: 0093A95E
loc_0093A989:   If var_1B4 > 0 Then GoTo loc_0093B8E7
  loc_0093A99D: var_1E0 = var_1E0 * 0003h
  loc_0093A9B1: var_190 = var_1E0 - 0002h
  loc_0093A9C6: var_238 = var_238 + 0001h
loc_0093A9D0:   var_238 = var_238
  loc_0093A9E5: var_2F4 = var_2F4 + 0001h
loc_0093A9EF:   var_2F4 = var_2F4
loc_0093AA04:   var_478 = var_1B4
loc_0093AA14:   If var_478 >= 501 Then GoTo loc_0093AA1F
loc_0093AA1D:   GoTo loc_0093AA2A
loc_0093AA1F:   'Referenced from: 0093AA14
loc_0093AA1F:   var_eax = Err.Raise
loc_0093AA24:   var_B08 = Err.Raise
loc_0093AA2A:   'Referenced from: 0093AA1D
  loc_0093AA31: var_474 = var_1E0 - 0002h - 0002h
loc_0093AA41:   If var_474 >= 501 Then GoTo loc_0093AA4C
loc_0093AA4A:   GoTo loc_0093AA57
loc_0093AA4C:   'Referenced from: 0093AA41
loc_0093AA4C:   var_eax = Err.Raise
loc_0093AA51:   var_B0C = Err.Raise
loc_0093AA57:   'Referenced from: 0093AA4A
loc_0093AA5E:   var_470 = var_238
loc_0093AA6B:   If var_470 >= 7 Then GoTo loc_0093AA76
loc_0093AA74:   GoTo loc_0093AA81
loc_0093AA76:   'Referenced from: 0093AA6B
loc_0093AA76:   var_eax = Err.Raise
loc_0093AA7B:   var_B10 = Err.Raise
loc_0093AA81:   'Referenced from: 0093AA74
loc_0093AA93:   var_478 = var_478 + var_474 * 501
  loc_0093AABB: var_238 = var_238 + 0001h
loc_0093AAC5:   var_238 = var_238
loc_0093AADA:   var_478 = var_1B4
loc_0093AAEA:   If var_478 >= 501 Then GoTo loc_0093AAF5
loc_0093AAF3:   GoTo loc_0093AB00
loc_0093AAF5:   'Referenced from: 0093AAEA
loc_0093AAF5:   var_eax = Err.Raise
loc_0093AAFA:   var_B14 = Err.Raise
loc_0093AB00:   'Referenced from: 0093AAF3
  loc_0093AB07: var_190 = var_190 + 0001h
  loc_0093AB14: var_474 = var_190 + 0001h
loc_0093AB24:   If var_474 >= 501 Then GoTo loc_0093AB2F
loc_0093AB2D:   GoTo loc_0093AB3A
loc_0093AB2F:   'Referenced from: 0093AB24
loc_0093AB2F:   var_eax = Err.Raise
loc_0093AB34:   var_B18 = Err.Raise
loc_0093AB3A:   'Referenced from: 0093AB2D
loc_0093AB41:   var_470 = var_238
loc_0093AB4E:   If var_470 >= 7 Then GoTo loc_0093AB59
loc_0093AB57:   GoTo loc_0093AB64
loc_0093AB59:   'Referenced from: 0093AB4E
loc_0093AB59:   var_eax = Err.Raise
loc_0093AB5E:   var_B1C = Err.Raise
loc_0093AB64:   'Referenced from: 0093AB57
loc_0093AB76:   var_478 = var_478 + var_474 * 501
  loc_0093AB9E: var_238 = var_238 + 0001h
loc_0093ABA8:   var_238 = var_238
loc_0093ABBD:   var_478 = var_1B4
loc_0093ABCD:   If var_478 >= 501 Then GoTo loc_0093ABD8
loc_0093ABD6:   GoTo loc_0093ABE3
loc_0093ABD8:   'Referenced from: 0093ABCD
loc_0093ABD8:   var_eax = Err.Raise
loc_0093ABDD:   var_B20 = Err.Raise
loc_0093ABE3:   'Referenced from: 0093ABD6
  loc_0093ABF7: var_474 = var_190 + 0002h
loc_0093AC07:   If var_474 >= 501 Then GoTo loc_0093AC12
loc_0093AC10:   GoTo loc_0093AC1D
loc_0093AC12:   'Referenced from: 0093AC07
loc_0093AC12:   var_eax = Err.Raise
loc_0093AC17:   var_B24 = Err.Raise
loc_0093AC1D:   'Referenced from: 0093AC10
loc_0093AC24:   var_470 = var_238
loc_0093AC31:   If var_470 >= 7 Then GoTo loc_0093AC3C
loc_0093AC3A:   GoTo loc_0093AC47
loc_0093AC3C:   'Referenced from: 0093AC31
loc_0093AC3C:   var_eax = Err.Raise
loc_0093AC41:   var_B28 = Err.Raise
loc_0093AC47:   'Referenced from: 0093AC3A
loc_0093AC59:   var_478 = var_478 + var_474 * 501
loc_0093AC85:   If var_2F4 <> 0 Then GoTo loc_0093AC89
loc_0093AC87:   GoTo loc_0093AC9F
loc_0093AC89:   'Referenced from: 0093AC85
loc_0093AC98:   If var_238 >= 5 Then GoTo loc_0093AC9F
loc_0093AC9A:   GoTo loc_0093B8DB
loc_0093AC9F:   'Referenced from: 0093AC87
loc_0093ACB1:   var_B8 = "NO"
  loc_0093AD0E: var_328 = Global.Printer
loc_0093AD13:   var_474 = var_328
  loc_0093AD5B: call __vbaPrintObj(var_006EA3B8, var_328, 00000003h, var_006EAC14)
loc_0093AD95:   var_348 = "##,##0"
loc_0093ADAB:   If var_470 >= 7 Then GoTo loc_0093ADB6
loc_0093ADB4:   GoTo loc_0093ADC1
loc_0093ADB6:   'Referenced from: 0093ADAB
loc_0093ADB6:   var_eax = Err.Raise
loc_0093ADBB:   var_B34 = Err.Raise
loc_0093ADC1:   'Referenced from: 0093ADB4
loc_0093ADD0:   var_3A0 = ecx + eax * 4
loc_0093ADFF:   var_150 = Format$(ecx + eax * 4, var_348)
  loc_0093AE24: 00000006h = 00000006h - Len(var_150)
  loc_0093AE90: var_328 = Global.Printer
loc_0093AE95:   var_474 = var_328
  loc_0093AEE4: call __vbaPrintObj(var_006EAC1C, var_328, var_BC, var_150, 00000001h, 00000001h, 00000001h)
  loc_0093AF4F: var_328 = Global.Printer
loc_0093AF54:   var_474 = var_328
  loc_0093AF9C: call __vbaPrintObj(var_006E89EC, var_328, var_006EAC28, 00000001h)
loc_0093AFD6:   var_348 = "###,###,##0"
loc_0093AFEC:   If var_470 >= 7 Then GoTo loc_0093AFF7
loc_0093AFF5:   GoTo loc_0093B002
loc_0093AFF7:   'Referenced from: 0093AFEC
loc_0093AFF7:   var_eax = Err.Raise
loc_0093AFFC:   var_B48 = Err.Raise
loc_0093B002:   'Referenced from: 0093AFF5
loc_0093B011:   var_3A0 = ecx + eax * 4
loc_0093B040:   var_150 = Format$(ecx + eax * 4, var_348)
  loc_0093B065: 0000000Bh = 0000000Bh - Len(var_150)
  loc_0093B0D1: var_328 = Global.Printer
loc_0093B0D6:   var_474 = var_328
  loc_0093B123: call __vbaPrintObj(var_006EABEC, var_328, var_BC, var_150, 00000001h, 00000001h)
loc_0093B15D:   var_348 = "###,###,##0"
loc_0093B173:   If var_470 >= 7 Then GoTo loc_0093B17E
loc_0093B17C:   GoTo loc_0093B189
loc_0093B17E:   'Referenced from: 0093B173
loc_0093B17E:   var_eax = Err.Raise
loc_0093B183:   var_B54 = Err.Raise
loc_0093B189:   'Referenced from: 0093B17C
loc_0093B198:   var_3A0 = ecx + eax * 4
loc_0093B1C7:   var_150 = Format$(ecx + eax * 4, var_348)
  loc_0093B1EC: 0000000Dh = 0000000Dh - Len(var_150)
  loc_0093B258: var_328 = Global.Printer
loc_0093B25D:   var_474 = var_328
  loc_0093B2AA: call __vbaPrintObj(var_006EABEC, var_328, var_BC, var_150, 00000001h, 00000001h)
loc_0093B2CC:   If var_238 >= 4 Then GoTo loc_0093B2D3
loc_0093B2CE:   GoTo loc_0093B906
loc_0093B2D3:   'Referenced from: 0093B2CC
loc_0093B2FA:   var_348 = "##,##0"
loc_0093B310:   If var_470 >= 7 Then GoTo loc_0093B31B
loc_0093B319:   GoTo loc_0093B326
loc_0093B31B:   'Referenced from: 0093B310
loc_0093B31B:   var_eax = Err.Raise
loc_0093B320:   var_B60 = Err.Raise
loc_0093B326:   'Referenced from: 0093B319
loc_0093B335:   var_3A0 = ecx + eax * 4
loc_0093B364:   var_150 = Format$(ecx + eax * 4, var_348)
  loc_0093B389: 0000000Ch = 0000000Ch - Len(var_150)
  loc_0093B3F5: var_328 = Global.Printer
loc_0093B3FA:   var_474 = var_328
  loc_0093B449: call __vbaPrintObj(var_006EAC1C, var_328, var_BC, var_150, 00000001h, 00000001h, 00000001h)
  loc_0093B4B4: var_328 = Global.Printer
loc_0093B4B9:   var_474 = var_328
  loc_0093B501: call __vbaPrintObj(var_006E89EC, var_328, var_006EAC28, 00000001h)
loc_0093B53B:   var_348 = "###,###,##0"
loc_0093B551:   If var_470 >= 7 Then GoTo loc_0093B55C
loc_0093B55A:   GoTo loc_0093B567
loc_0093B55C:   'Referenced from: 0093B551
loc_0093B55C:   var_eax = Err.Raise
loc_0093B561:   var_B74 = Err.Raise
loc_0093B567:   'Referenced from: 0093B55A
loc_0093B576:   var_3A0 = ecx + eax * 4
loc_0093B5A5:   var_150 = Format$(ecx + eax * 4, var_348)
  loc_0093B5CA: 0000000Bh = 0000000Bh - Len(var_150)
  loc_0093B636: var_328 = Global.Printer
loc_0093B63B:   var_474 = var_328
  loc_0093B688: call __vbaPrintObj(var_006EABEC, var_328, var_BC, var_150, 00000001h, 00000001h)
loc_0093B6C2:   var_348 = "###,###,##0"
loc_0093B6D8:   If var_470 >= 7 Then GoTo loc_0093B6E3
loc_0093B6E1:   GoTo loc_0093B6EE
loc_0093B6E3:   'Referenced from: 0093B6D8
loc_0093B6E3:   var_eax = Err.Raise
loc_0093B6E8:   var_B80 = Err.Raise
loc_0093B6EE:   'Referenced from: 0093B6E1
loc_0093B6FD:   var_3A0 = ecx + eax * 4
loc_0093B72C:   var_150 = Format$(ecx + eax * 4, var_348)
  loc_0093B751: 0000000Eh = 0000000Eh - Len(var_150)
  loc_0093B7BD: var_328 = Global.Printer
loc_0093B7C2:   var_474 = var_328
  loc_0093B80F: call __vbaPrintObj(var_006EA3C4, var_328, var_BC, var_150, 00000001h, 00000001h)
  loc_0093B82D: var_54 = var_54 + 0001h
loc_0093B837:   var_54 = var_54
loc_0093B84D:   If var_2F4 <> 0 Then GoTo loc_0093B87E
loc_0093B85E:   If var_EE085E <= 0 Then GoTo loc_0093B87C
  loc_0093B86E: var_eax = GoSub var_518
  loc_0093B875: If GoSub var_518 <> 0 Then GoTo loc_0093B87C
loc_0093B877:   GoTo loc_00944A80
loc_0093B87C:   'Referenced from: 0093B85E
loc_0093B87C:   GoTo loc_0093B8DB
loc_0093B87E:   'Referenced from: 0093B84D
loc_0093B89F:   If var_54 >= 0 Then GoTo loc_0093B8A3
loc_0093B8A1:   GoTo loc_0093B8DB
loc_0093B8A3:   'Referenced from: 0093B89F
  loc_0093B8B1: var_eax = GoSub var_518
  loc_0093B8B8: If GoSub var_518 <> 0 Then GoTo loc_0093B8BF
loc_0093B8BA:   GoTo loc_00944A80
loc_0093B8BF:   'Referenced from: 0093B8B8
  loc_0093B8CD: var_eax = GoSub var_518
  loc_0093B8D4: If GoSub var_518 <> 0 Then GoTo loc_0093B8DB
loc_0093B8D6:   GoTo loc_00943610
loc_0093B8DB:   'Referenced from: 0093AC9A
loc_0093B8E2:   GoTo loc_0093A960
loc_0093B8E7:   'Referenced from: 0093A989
loc_0093B8EE:   GoTo loc_0093A8D2
loc_0093B8F3:   'Referenced from: 0093A8FB
  loc_0093B901: call Return(var_518)
loc_0093B906:   'Referenced from: 0093B2CE
loc_0093B924:   If var_EE085E <= 0 Then GoTo loc_0093B942
  loc_0093B934: var_eax = GoSub var_518
  loc_0093B93B: If GoSub var_518 <> 0 Then GoTo loc_0093B942
loc_0093B93D:   GoTo loc_00944A80
loc_0093B942:   'Referenced from: 0093B924
  loc_0093B950: call Return(var_518)
loc_0093B955:   'Referenced from: 0093963A
  loc_0093B9AD: var_eax = Unknown_VTable_Call[eax+0000001Ch]
  loc_0093B9B2: var_474 = Unknown_VTable_Call[eax+0000001Ch]
loc_0093B9EE:   var_588 = var_328
  loc_0093BA29: var_eax = Unknown_VTable_Call[eax+000000D0h]
  loc_0093BA31: var_470 = Unknown_VTable_Call[eax+000000D0h]
loc_0093BA70:   var_474 = var_328
  loc_0093BAB8: var_eax = Unknown_VTable_Call[eax+00000028h]
  loc_0093BABD: var_478 = Unknown_VTable_Call[eax+00000028h]
loc_0093BAF9:   var_58C = var_32C
  loc_0093BB3F: var_eax = Unknown_VTable_Call[eax+00000040h]
  loc_0093BB44: var_470 = Unknown_VTable_Call[eax+00000040h]
  loc_0093BB85: call __vbaCastObj(var_328, var_006EA910, var_108, var_328, var_314, var_58C, var_474, var_3A8, var_3A4, var_3A0, var_39C, var_108, var_588, var_470)
loc_0093BBC6:   var_304 = CInt(1)
  loc_0093BBDF: var_eax = Unknown_VTable_Call[eax+0000004Ch]
  loc_0093BBE4: var_470 = Unknown_VTable_Call[eax+0000004Ch]
loc_0093BC46:   var_3E0 = "Order"
  loc_0093BC69: var_eax = Unknown_VTable_Call[eax+000000D0h]
  loc_0093BC71: var_470 = Unknown_VTable_Call[eax+000000D0h]
loc_0093BD2F:   var_3E0 = "First Value"
  loc_0093BD52: var_eax = Unknown_VTable_Call[eax+000000D0h]
  loc_0093BD5A: var_470 = Unknown_VTable_Call[eax+000000D0h]
loc_0093BE18:   var_3E0 = "Second Value"
  loc_0093BE3B: var_eax = Unknown_VTable_Call[eax+000000D0h]
  loc_0093BE43: var_470 = Unknown_VTable_Call[eax+000000D0h]
loc_0093BF01:   var_3E0 = "Seed Number"
  loc_0093BF24: var_eax = Unknown_VTable_Call[eax+000000D0h]
  loc_0093BF2C: var_470 = Unknown_VTable_Call[eax+000000D0h]
loc_0093BFEA:   var_3E0 = "Frame Size"
  loc_0093C00D: var_eax = Unknown_VTable_Call[eax+000000D0h]
  loc_0093C015: var_470 = Unknown_VTable_Call[eax+000000D0h]
loc_0093C0D3:   var_3E0 = "          Windows RAT-STATS"
  loc_0093C0F6: var_eax = Unknown_VTable_Call[eax+000000D0h]
  loc_0093C0FE: var_470 = Unknown_VTable_Call[eax+000000D0h]
loc_0093C1BC:   var_3E0 = "           Statistical Software"
  loc_0093C1DF: var_eax = Unknown_VTable_Call[eax+000000D0h]
  loc_0093C1E7: var_470 = Unknown_VTable_Call[eax+000000D0h]
loc_0093C2A5:   var_3E0 = "      Random Number Generator"
  loc_0093C2C8: var_eax = Unknown_VTable_Call[eax+000000D0h]
  loc_0093C2D0: var_470 = Unknown_VTable_Call[eax+000000D0h]
loc_0093C38E:   var_3E0 = "Date:"
  loc_0093C3B1: var_eax = Unknown_VTable_Call[eax+000000D0h]
  loc_0093C3B9: var_470 = Unknown_VTable_Call[eax+000000D0h]
loc_0093C477:   var_3E0 = "Time:"
  loc_0093C49A: var_eax = Unknown_VTable_Call[eax+000000D0h]
  loc_0093C4A2: var_470 = Unknown_VTable_Call[eax+000000D0h]
loc_0093C560:   var_3E0 = "Audit:"
  loc_0093C583: var_eax = Unknown_VTable_Call[eax+000000D0h]
  loc_0093C58B: var_470 = Unknown_VTable_Call[eax+000000D0h]
  loc_0093C66D: var_eax = Unknown_VTable_Call[eax+000000D0h]
  loc_0093C675: var_470 = Unknown_VTable_Call[eax+000000D0h]
loc_0093C77B:   var_360 = Format$(Now, "m/d/yyyy")
  loc_0093C79A: var_eax = Unknown_VTable_Call[eax+000000D0h]
  loc_0093C7A2: var_470 = Unknown_VTable_Call[eax+000000D0h]
loc_0093C8C7:   var_360 = Format$(Now, "h:mm")
  loc_0093C8E6: var_eax = Unknown_VTable_Call[eax+000000D0h]
  loc_0093C8EE: var_470 = Unknown_VTable_Call[eax+000000D0h]
loc_0093C9C8:   var_3A0 = vbNullString
loc_0093CA40:   var_3E0 = Format$(vbNullString, "######.00")
  loc_0093CA5F: var_eax = Unknown_VTable_Call[eax+000000D0h]
  loc_0093CA67: var_470 = Unknown_VTable_Call[eax+000000D0h]
loc_0093CB22:   var_3A0 = vbNullString
loc_0093CB9A:   var_3E0 = Format$(vbNullString, "#,###,###,###")
  loc_0093CBB9: var_eax = Unknown_VTable_Call[eax+000000D0h]
  loc_0093CBC1: var_470 = Unknown_VTable_Call[eax+000000D0h]
loc_0093CC72:   GoTo loc_0093CC8F
loc_0093CC74:
loc_0093CC7B:   var_1E0 = var_1E0 + 1
loc_0093CC88:   var_1E0 = var_1E0
loc_0093CC8F:   'Referenced from: 0093CC72
loc_0093CC9D:   If var_1E0 > 0 Then GoTo loc_0093D510
loc_0093CCB1:   var_470 = var_1E0
loc_0093CCC1:   If var_470 >= 501 Then GoTo loc_0093CCCC
loc_0093CCCA:   GoTo loc_0093CCD7
loc_0093CCCC:   'Referenced from: 0093CCC1
loc_0093CCCC:   var_eax = Err.Raise
loc_0093CCD1:   var_BE4 = Err.Raise
loc_0093CCD7:   'Referenced from: 0093CCCA
loc_0093CCE7:   var_4E8 = ecx + eax * 2
loc_0093CD00:   GoTo loc_0093CD1D
loc_0093CD02:
loc_0093CD09:   var_1B4 = var_1B4 + 1
loc_0093CD16:   var_1B4 = var_1B4
loc_0093CD1D:   'Referenced from: 0093CD00
loc_0093CD2B:   If var_1B4 > 0 Then GoTo loc_0093D504
  loc_0093CD3F: var_1E0 = var_1E0 * 0003h
  loc_0093CD53: var_190 = var_1E0 - 0002h
  loc_0093CD68: var_2F4 = var_2F4 + 0001h
loc_0093CD72:   var_2F4 = var_2F4
loc_0093CD87:   var_478 = var_1B4
loc_0093CD97:   If var_478 >= 501 Then GoTo loc_0093CDA2
loc_0093CDA0:   GoTo loc_0093CDAD
loc_0093CDA2:   'Referenced from: 0093CD97
loc_0093CDA2:   var_eax = Err.Raise
loc_0093CDA7:   var_BE8 = Err.Raise
loc_0093CDAD:   'Referenced from: 0093CDA0
  loc_0093CDB4: var_474 = var_1E0 - 0002h - 0002h
loc_0093CDC4:   If var_474 >= 501 Then GoTo loc_0093CDCF
loc_0093CDCD:   GoTo loc_0093CDDA
loc_0093CDCF:   'Referenced from: 0093CDC4
loc_0093CDCF:   var_eax = Err.Raise
loc_0093CDD4:   var_BEC = Err.Raise
loc_0093CDDA:   'Referenced from: 0093CDCD
loc_0093CDEB:   If var_470 >= 7 Then GoTo loc_0093CDF6
loc_0093CDF4:   GoTo loc_0093CE01
loc_0093CDF6:   'Referenced from: 0093CDEB
loc_0093CDF6:   var_eax = Err.Raise
loc_0093CDFB:   var_BF0 = Err.Raise
loc_0093CE01:   'Referenced from: 0093CDF4
loc_0093CE13:   var_478 = var_478 + var_474 * 501
loc_0093CE3B:   var_478 = var_1B4
loc_0093CE4B:   If var_478 >= 501 Then GoTo loc_0093CE56
loc_0093CE54:   GoTo loc_0093CE61
loc_0093CE56:   'Referenced from: 0093CE4B
loc_0093CE56:   var_eax = Err.Raise
loc_0093CE5B:   var_BF4 = Err.Raise
loc_0093CE61:   'Referenced from: 0093CE54
  loc_0093CE68: var_190 = var_190 + 0001h
  loc_0093CE75: var_474 = var_190 + 0001h
loc_0093CE85:   If var_474 >= 501 Then GoTo loc_0093CE90
loc_0093CE8E:   GoTo loc_0093CE9B
loc_0093CE90:   'Referenced from: 0093CE85
loc_0093CE90:   var_eax = Err.Raise
loc_0093CE95:   var_BF8 = Err.Raise
loc_0093CE9B:   'Referenced from: 0093CE8E
loc_0093CEAC:   If var_470 >= 7 Then GoTo loc_0093CEB7
loc_0093CEB5:   GoTo loc_0093CEC2
loc_0093CEB7:   'Referenced from: 0093CEAC
loc_0093CEB7:   var_eax = Err.Raise
loc_0093CEBC:   var_BFC = Err.Raise
loc_0093CEC2:   'Referenced from: 0093CEB5
loc_0093CED4:   var_478 = var_478 + var_474 * 501
loc_0093CEFC:   var_478 = var_1B4
loc_0093CF0C:   If var_478 >= 501 Then GoTo loc_0093CF17
loc_0093CF15:   GoTo loc_0093CF22
loc_0093CF17:   'Referenced from: 0093CF0C
loc_0093CF17:   var_eax = Err.Raise
loc_0093CF1C:   var_C00 = Err.Raise
loc_0093CF22:   'Referenced from: 0093CF15
  loc_0093CF36: var_474 = var_190 + 0002h
loc_0093CF46:   If var_474 >= 501 Then GoTo loc_0093CF51
loc_0093CF4F:   GoTo loc_0093CF5C
loc_0093CF51:   'Referenced from: 0093CF46
loc_0093CF51:   var_eax = Err.Raise
loc_0093CF56:   var_C04 = Err.Raise
loc_0093CF5C:   'Referenced from: 0093CF4F
loc_0093CF6D:   If var_470 >= 7 Then GoTo loc_0093CF78
loc_0093CF76:   GoTo loc_0093CF83
loc_0093CF78:   'Referenced from: 0093CF6D
loc_0093CF78:   var_eax = Err.Raise
loc_0093CF7D:   var_C08 = Err.Raise
loc_0093CF83:   'Referenced from: 0093CF76
loc_0093CF95:   var_478 = var_478 + var_474 * 501
loc_0093CFD6:   var_348 = "#####0"
loc_0093CFEC:   If var_470 >= 7 Then GoTo loc_0093CFF7
loc_0093CFF5:   GoTo loc_0093D002
loc_0093CFF7:   'Referenced from: 0093CFEC
loc_0093CFF7:   var_eax = Err.Raise
loc_0093CFFC:   var_C0C = Err.Raise
loc_0093D002:   'Referenced from: 0093CFF5
loc_0093D011:   var_3A0 = ecx + eax * 4
loc_0093D085:   var_3E0 = Format$(ecx + eax * 4, var_348)
  loc_0093D0A4: var_eax = Unknown_VTable_Call[eax+000000D0h]
  loc_0093D0AC: var_470 = Unknown_VTable_Call[eax+000000D0h]
loc_0093D183:   var_348 = "#####0"
loc_0093D199:   If var_470 >= 7 Then GoTo loc_0093D1A4
loc_0093D1A2:   GoTo loc_0093D1AF
loc_0093D1A4:   'Referenced from: 0093D199
loc_0093D1A4:   var_eax = Err.Raise
loc_0093D1A9:   var_C14 = Err.Raise
loc_0093D1AF:   'Referenced from: 0093D1A2
loc_0093D1BE:   var_3A0 = ecx + eax * 4
loc_0093D232:   var_3E0 = Format$(ecx + eax * 4, var_348)
  loc_0093D251: var_eax = Unknown_VTable_Call[eax+000000D0h]
  loc_0093D259: var_470 = Unknown_VTable_Call[eax+000000D0h]
loc_0093D330:   var_348 = "#####0"
loc_0093D346:   If var_470 >= 7 Then GoTo loc_0093D351
loc_0093D34F:   GoTo loc_0093D35C
loc_0093D351:   'Referenced from: 0093D346
loc_0093D351:   var_eax = Err.Raise
loc_0093D356:   var_C1C = Err.Raise
loc_0093D35C:   'Referenced from: 0093D34F
loc_0093D36B:   var_3A0 = ecx + eax * 4
loc_0093D3DF:   var_3E0 = Format$(ecx + eax * 4, var_348)
  loc_0093D3FE: var_eax = Unknown_VTable_Call[eax+000000D0h]
  loc_0093D406: var_470 = Unknown_VTable_Call[eax+000000D0h]
loc_0093D4F3:   var_304 = var_304 + 1
loc_0093D4FF:   GoTo loc_0093CD02
loc_0093D504:   'Referenced from: 0093CD2B
loc_0093D50B:   GoTo loc_0093CC74
loc_0093D510:   'Referenced from: 0093CC9D
  loc_0093D590: var_eax = Unknown_VTable_Call[eax+00000058h]
  loc_0093D595: var_474 = Unknown_VTable_Call[eax+00000058h]
  loc_0093D685: var_eax = Unknown_VTable_Call[eax+00000058h]
  loc_0093D68A: var_47C = Unknown_VTable_Call[eax+00000058h]
  loc_0093D77A: var_eax = Unknown_VTable_Call[eax+000000A0h]
  loc_0093D782: var_484 = Unknown_VTable_Call[eax+000000A0h]
  loc_0093D875: var_eax = Unknown_VTable_Call[eax+000000B0h]
  loc_0093D87D: var_474 = Unknown_VTable_Call[eax+000000B0h]
  loc_0093D8EC: call __vbaVarLateMemSt(var_328."Font", var_3A0, var_39C)
  loc_0093D987: var_eax = Unknown_VTable_Call[eax+00000058h]
  loc_0093D98C: var_474 = Unknown_VTable_Call[eax+00000058h]
  loc_0093DA7C: var_eax = Unknown_VTable_Call[eax+00000058h]
  loc_0093DA81: var_47C = Unknown_VTable_Call[eax+00000058h]
  loc_0093DB71: var_eax = Unknown_VTable_Call[eax+000000A0h]
  loc_0093DB79: var_484 = Unknown_VTable_Call[eax+000000A0h]
  loc_0093DC6F: var_eax = Unknown_VTable_Call[eax+000000B0h]
  loc_0093DC77: var_474 = Unknown_VTable_Call[eax+000000B0h]
  loc_0093DD5F: var_eax = Unknown_VTable_Call[eax+00000058h]
  loc_0093DD64: var_474 = Unknown_VTable_Call[eax+00000058h]
  loc_0093DE54: var_eax = Unknown_VTable_Call[eax+00000058h]
  loc_0093DE59: var_47C = Unknown_VTable_Call[eax+00000058h]
  loc_0093DF49: var_eax = Unknown_VTable_Call[eax+000000A0h]
  loc_0093DF51: var_484 = Unknown_VTable_Call[eax+000000A0h]
  loc_0093E044: var_eax = Unknown_VTable_Call[eax+000000B0h]
  loc_0093E04C: var_474 = Unknown_VTable_Call[eax+000000B0h]
  loc_0093E0BB: call __vbaVarLateMemSt(var_328."Font", var_3A0, var_39C)
  loc_0093E156: var_eax = Unknown_VTable_Call[eax+00000058h]
  loc_0093E15B: var_474 = Unknown_VTable_Call[eax+00000058h]
  loc_0093E24B: var_eax = Unknown_VTable_Call[eax+00000058h]
  loc_0093E250: var_47C = Unknown_VTable_Call[eax+00000058h]
  loc_0093E340: var_eax = Unknown_VTable_Call[eax+000000A0h]
  loc_0093E348: var_484 = Unknown_VTable_Call[eax+000000A0h]
  loc_0093E43B: var_eax = Unknown_VTable_Call[eax+000000B0h]
  loc_0093E443: var_474 = Unknown_VTable_Call[eax+000000B0h]
  loc_0093E4B2: call __vbaVarLateMemSt(var_328."Font", var_3A0, var_39C)
  loc_0093E54D: var_eax = Unknown_VTable_Call[eax+00000058h]
  loc_0093E552: var_474 = Unknown_VTable_Call[eax+00000058h]
  loc_0093E642: var_eax = Unknown_VTable_Call[eax+00000058h]
  loc_0093E647: var_47C = Unknown_VTable_Call[eax+00000058h]
  loc_0093E737: var_eax = Unknown_VTable_Call[eax+000000A0h]
  loc_0093E73F: var_484 = Unknown_VTable_Call[eax+000000A0h]
  loc_0093E835: var_eax = Unknown_VTable_Call[eax+000000B0h]
  loc_0093E83D: var_474 = Unknown_VTable_Call[eax+000000B0h]
  loc_0093E913: var_eax = Unknown_VTable_Call[eax+000000B0h]
  loc_0093E91B: var_474 = Unknown_VTable_Call[eax+000000B0h]
  loc_0093E98A: call __vbaVarLateMemSt(var_328."Font", var_3A0, var_39C, var_3A4, var_3A0, var_39C)
  loc_0093EA25: var_eax = Unknown_VTable_Call[eax+00000058h]
  loc_0093EA2A: var_474 = Unknown_VTable_Call[eax+00000058h]
  loc_0093EB1A: var_eax = Unknown_VTable_Call[eax+00000058h]
  loc_0093EB1F: var_47C = Unknown_VTable_Call[eax+00000058h]
  loc_0093EC0F: var_eax = Unknown_VTable_Call[eax+000000A0h]
  loc_0093EC17: var_484 = Unknown_VTable_Call[eax+000000A0h]
  loc_0093ED0D: var_eax = Unknown_VTable_Call[eax+000000B0h]
  loc_0093ED15: var_474 = Unknown_VTable_Call[eax+000000B0h]
  loc_0093EDEB: var_eax = Unknown_VTable_Call[eax+000000B0h]
  loc_0093EDF3: var_474 = Unknown_VTable_Call[eax+000000B0h]
  loc_0093EE59: var_348 = var_328."Font"
  loc_0093EE62: call __vbaVarLateMemSt(var_348, var_3A0, var_39C, var_3A4, var_3A0, var_39C)
  loc_0093EEFD: var_eax = Unknown_VTable_Call[eax+00000058h]
  loc_0093EF02: var_474 = Unknown_VTable_Call[eax+00000058h]
  loc_0093EFF2: var_eax = Unknown_VTable_Call[eax+00000058h]
  loc_0093EFF7: var_47C = Unknown_VTable_Call[eax+00000058h]
  loc_0093F0FD: var_eax = Unknown_VTable_Call[eax+000000A0h]
  loc_0093F105: var_484 = Unknown_VTable_Call[eax+000000A0h]
  loc_0093F202: var_eax = Unknown_VTable_Call[eax+000000B0h]
  loc_0093F20A: var_474 = Unknown_VTable_Call[eax+000000B0h]
  loc_0093F2F2: var_eax = Unknown_VTable_Call[eax+00000058h]
  loc_0093F2F7: var_474 = Unknown_VTable_Call[eax+00000058h]
  loc_0093F3E7: var_eax = Unknown_VTable_Call[eax+00000058h]
  loc_0093F3EC: var_47C = Unknown_VTable_Call[eax+00000058h]
  loc_0093F4DC: var_eax = Unknown_VTable_Call[eax+000000A0h]
  loc_0093F4E4: var_484 = Unknown_VTable_Call[eax+000000A0h]
  loc_0093F5DA: var_eax = Unknown_VTable_Call[eax+000000B0h]
  loc_0093F5E2: var_474 = Unknown_VTable_Call[eax+000000B0h]
  loc_0093F6CA: var_eax = Unknown_VTable_Call[eax+00000058h]
  loc_0093F6CF: var_474 = Unknown_VTable_Call[eax+00000058h]
  loc_0093F7BF: var_eax = Unknown_VTable_Call[eax+00000058h]
  loc_0093F7C4: var_47C = Unknown_VTable_Call[eax+00000058h]
  loc_0093F8B4: var_eax = Unknown_VTable_Call[eax+000000A0h]
  loc_0093F8BC: var_484 = Unknown_VTable_Call[eax+000000A0h]
loc_0093F948:   var_3A0 = "0.00"
  loc_0093F9B2: var_eax = Unknown_VTable_Call[eax+000000B0h]
  loc_0093F9BA: var_474 = Unknown_VTable_Call[eax+000000B0h]
  loc_0093FAB8: var_eax = Unknown_VTable_Call[eax+00000058h]
  loc_0093FABD: var_474 = Unknown_VTable_Call[eax+00000058h]
  loc_0093FB4E: call __vbaVarLateMemSt(var_348)
  loc_0093FBFF: var_eax = Unknown_VTable_Call[eax+00000058h]
  loc_0093FC04: var_474 = Unknown_VTable_Call[eax+00000058h]
  loc_0093FC95: call __vbaVarLateMemSt(var_348)
  loc_0093FD44: var_eax = Unknown_VTable_Call[eax+00000058h]
  loc_0093FD49: var_474 = Unknown_VTable_Call[eax+00000058h]
  loc_0093FDDA: call __vbaVarLateMemSt(var_348)
  loc_0093FE8B: var_eax = Unknown_VTable_Call[eax+00000058h]
  loc_0093FE90: var_474 = Unknown_VTable_Call[eax+00000058h]
  loc_0093FF21: call __vbaVarLateMemSt(var_348)
  loc_0093FFBC: var_eax = Unknown_VTable_Call[eax+00000058h]
  loc_0093FFC1: var_474 = Unknown_VTable_Call[eax+00000058h]
  loc_00940046: var_358 = Me.
loc_0094008B:   var_304 = CInt(1)
  loc_0094009E: call Return(var_518)
loc_009400A3:   'Referenced from: 00939700
loc_009400FB:   var_328 = DBEngine.Workspaces
loc_00940100:   var_474 = var_328
loc_0094017C:   DBEngine.DefaultPassword = False
loc_00940181:   var_47C = eax
loc_009401BD:   var_590 = var_32C
loc_009401ED:   On Error Resume Next
  loc_0094023B: var_eax = DBEngine.CreateDatabase var_110, ";LANGID=0x0409;CP=1252;COUNTRY=0", 10
loc_00940240:   var_470 = eax
loc_00940279:   var_594 = var_328
  loc_0094032C: var_eax = DBEngine.OpenDatabase var_110, var_3A8, var_3A4, var_3A0
  loc_00940331: var_470 = DBEngine.OpenDatabase var_110, var_3A8, var_3A4, var_3A0
loc_0094036A:   var_598 = var_328
loc_009403A8:   var_2F0 = var_EE0124 & "-Values"
loc_009403F6:   var_3A0 = var_2F0
loc_0094046B:   var_eax = DBEngine.Rollback
loc_00940470:   var_470 = DBEngine.Rollback
loc_009404AC:   var_59C = var_328
loc_009404F7:   var_3A0 = "Order"
  loc_00940556: var_eax = DBEngine.SetDefaultWorkspace "Order", var_3A4
  loc_0094055B: var_470 = DBEngine.SetDefaultWorkspace "Order", var_3A4
loc_00940594:   var_5A0 = var_328
loc_009405C9:   var_eax = DBEngine.FreeLocks
loc_009405CE:   var_470 = DBEngine.FreeLocks
loc_0094062E:   DBEngine.IniPath = var_318
loc_00940633:   var_478 = eax
loc_009406B0:   var_3A0 = "First-Value"
  loc_0094070F: var_eax = DBEngine.SetDefaultWorkspace "First-Value", var_3A4
  loc_00940714: var_470 = DBEngine.SetDefaultWorkspace "First-Value", var_3A4
loc_0094074D:   var_5A4 = var_328
loc_00940782:   var_eax = DBEngine.FreeLocks
loc_00940787:   var_470 = DBEngine.FreeLocks
loc_009407E7:   DBEngine.IniPath = var_318
loc_009407EC:   var_478 = eax
loc_00940869:   var_3A0 = "Second-Value"
  loc_009408C8: var_eax = DBEngine.SetDefaultWorkspace "Second-Value", var_3A4
  loc_009408CD: var_470 = DBEngine.SetDefaultWorkspace "Second-Value", var_3A4
loc_00940906:   var_5A8 = var_328
loc_0094093B:   var_eax = DBEngine.FreeLocks
loc_00940940:   var_470 = DBEngine.FreeLocks
loc_009409A0:   DBEngine.IniPath = var_318
loc_009409A5:   var_478 = eax
loc_00940A22:   var_3A0 = "Seed-Number"
  loc_00940A81: var_eax = DBEngine.SetDefaultWorkspace "Seed-Number", var_3A4
  loc_00940A86: var_470 = DBEngine.SetDefaultWorkspace "Seed-Number", var_3A4
loc_00940ABF:   var_5AC = var_328
loc_00940AF4:   var_eax = DBEngine.FreeLocks
loc_00940AF9:   var_470 = DBEngine.FreeLocks
loc_00940B59:   DBEngine.IniPath = var_318
loc_00940B5E:   var_478 = eax
loc_00940BDB:   var_3A0 = "Date"
  loc_00940C3A: var_eax = DBEngine.SetDefaultWorkspace "Date", var_3A4
  loc_00940C3F: var_470 = DBEngine.SetDefaultWorkspace "Date", var_3A4
loc_00940C78:   var_5B0 = var_328
loc_00940CAD:   var_eax = DBEngine.FreeLocks
loc_00940CB2:   var_470 = DBEngine.FreeLocks
loc_00940D12:   DBEngine.IniPath = var_318
loc_00940D17:   var_478 = eax
loc_00940D94:   var_3A0 = "Time"
  loc_00940DF3: var_eax = DBEngine.SetDefaultWorkspace "Time", var_3A4
  loc_00940DF8: var_470 = DBEngine.SetDefaultWorkspace "Time", var_3A4
loc_00940E31:   var_5B4 = var_328
loc_00940E66:   var_eax = DBEngine.FreeLocks
loc_00940E6B:   var_470 = DBEngine.FreeLocks
loc_00940ECB:   DBEngine.IniPath = var_318
loc_00940ED0:   var_478 = eax
loc_00940F27:   On Error Resume Next
  loc_00940F48: var_eax = DBEngine.Idle var_328
  loc_00940F4D: var_470 = DBEngine.Idle var_328
loc_00940FA3:   DBEngine.DefaultUser = var_2F0
loc_00940FA8:   var_478 = eax
  loc_00941005: var_eax = DBEngine.Idle var_328
  loc_0094100A: var_470 = DBEngine.Idle var_328
loc_00941056:   Set var_32C = var_70
loc_0094106A:   DBEngine.IniPath = var_32C
loc_0094106F:   var_478 = eax
  loc_00941157: var_eax = Unknown_VTable_Call[eax+000000BCh]
  loc_0094115F: var_470 = Unknown_VTable_Call[eax+000000BCh]
loc_0094119E:   var_5B8 = var_328
  loc_009411D2: var_eax = Unknown_VTable_Call[eax+000000E4h]
  loc_009411DA: var_470 = Unknown_VTable_Call[eax+000000E4h]
  loc_00941228: var_eax = Unknown_VTable_Call[eax+000000C0h]
  loc_00941230: var_470 = Unknown_VTable_Call[eax+000000C0h]
  loc_0094127A: ecx = 006EAF7Ch
loc_0094128F:   If var_EE085C <> 0 Then GoTo loc_009418F9
loc_009412C1:   var_3A0 = vbNullString
loc_009412F4:   var_150 = Format$(vbNullString, "######.00")
loc_00941316:   var_C0 = "Seed-Number"
  loc_00941337: var_eax = Unknown_VTable_Call[eax+000000B4h]
  loc_0094133F: var_470 = Unknown_VTable_Call[eax+000000B4h]
loc_0094138A:   var_3A0 = var_C0
loc_009413C3:   DBEngine.DefaultPassword = var_C0
loc_009413C8:   var_478 = eax
loc_00941410:   var_3B0 = var_150
  loc_00941442: var_eax = DBEngine.CompactDatabase var_150, var_3B4, var_3B0, var_3AC, var_310
  loc_00941447: var_480 = DBEngine.CompactDatabase var_150, var_3B4, var_3B0, var_3AC, var_310
loc_009414EC:   var_150 = Format$(Now, "m/d/yyyy")
loc_0094151B:   var_C0 = "Date"
  loc_0094153C: var_eax = Unknown_VTable_Call[eax+000000B4h]
  loc_00941544: var_470 = Unknown_VTable_Call[eax+000000B4h]
loc_0094158F:   var_3A0 = var_C0
loc_009415C8:   DBEngine.DefaultPassword = var_C0
loc_009415CD:   var_478 = eax
loc_00941615:   var_3B0 = var_150
  loc_00941647: var_eax = DBEngine.CompactDatabase var_150, var_3B4, var_3B0, var_3AC, var_154
  loc_0094164C: var_480 = DBEngine.CompactDatabase var_150, var_3B4, var_3B0, var_3AC, var_154
loc_009416F1:   var_150 = Format$(Now, "h:mm")
loc_00941720:   var_C0 = "Time"
  loc_00941741: var_eax = Unknown_VTable_Call[eax+000000B4h]
  loc_00941749: var_470 = Unknown_VTable_Call[eax+000000B4h]
loc_00941794:   var_3A0 = var_C0
loc_009417CD:   DBEngine.DefaultPassword = var_C0
loc_009417D2:   var_478 = eax
loc_0094181A:   var_3B0 = var_150
  loc_0094184C: var_eax = DBEngine.CompactDatabase var_150, var_3B4, var_3B0, var_3AC
  loc_00941851: var_480 = DBEngine.CompactDatabase var_150, var_3B4, var_3B0, var_3AC
  loc_009418B8: var_eax = Unknown_VTable_Call[eax+00000164h]
  loc_009418C0: var_470 = Unknown_VTable_Call[eax+00000164h]
loc_0094191B:   GoTo loc_00941938
loc_0094191D:
loc_00941924:   var_1E0 = var_1E0 + 1
loc_00941931:   var_1E0 = var_1E0
loc_00941938:   'Referenced from: 0094191B
loc_00941946:   If var_1E0 > 0 Then GoTo loc_009429F6
loc_0094195A:   var_470 = var_1E0
loc_0094196A:   If var_470 >= 501 Then GoTo loc_00941975
loc_00941973:   GoTo loc_00941980
loc_00941975:   'Referenced from: 0094196A
loc_00941975:   var_eax = Err.Raise
loc_0094197A:   var_E20 = Err.Raise
loc_00941980:   'Referenced from: 00941973
loc_00941990:   var_4F8 = ecx + eax * 2
loc_009419A9:   GoTo loc_009419C6
loc_009419AB:
loc_009419B2:   var_1B4 = var_1B4 + 1
loc_009419BF:   var_1B4 = var_1B4
loc_009419C6:   'Referenced from: 009419A9
loc_009419D4:   If var_1B4 > 0 Then GoTo loc_009429EA
  loc_009419E8: var_1E0 = var_1E0 * 0003h
  loc_009419FC: var_190 = var_1E0 - 0002h
  loc_00941A11: var_2F4 = var_2F4 + 0001h
loc_00941A1B:   var_2F4 = var_2F4
loc_00941A30:   var_478 = var_1B4
loc_00941A40:   If var_478 >= 501 Then GoTo loc_00941A4B
loc_00941A49:   GoTo loc_00941A56
loc_00941A4B:   'Referenced from: 00941A40
loc_00941A4B:   var_eax = Err.Raise
loc_00941A50:   var_E24 = Err.Raise
loc_00941A56:   'Referenced from: 00941A49
  loc_00941A5D: var_474 = var_1E0 - 0002h - 0002h
loc_00941A6D:   If var_474 >= 501 Then GoTo loc_00941A78
loc_00941A76:   GoTo loc_00941A83
loc_00941A78:   'Referenced from: 00941A6D
loc_00941A78:   var_eax = Err.Raise
loc_00941A7D:   var_E28 = Err.Raise
loc_00941A83:   'Referenced from: 00941A76
loc_00941A94:   If var_470 >= 7 Then GoTo loc_00941A9F
loc_00941A9D:   GoTo loc_00941AAA
loc_00941A9F:   'Referenced from: 00941A94
loc_00941A9F:   var_eax = Err.Raise
loc_00941AA4:   var_E2C = Err.Raise
loc_00941AAA:   'Referenced from: 00941A9D
loc_00941ABC:   var_478 = var_478 + var_474 * 501
loc_00941AE4:   var_478 = var_1B4
loc_00941AF4:   If var_478 >= 501 Then GoTo loc_00941AFF
loc_00941AFD:   GoTo loc_00941B0A
loc_00941AFF:   'Referenced from: 00941AF4
loc_00941AFF:   var_eax = Err.Raise
loc_00941B04:   var_E30 = Err.Raise
loc_00941B0A:   'Referenced from: 00941AFD
  loc_00941B11: var_190 = var_190 + 0001h
  loc_00941B1E: var_474 = var_190 + 0001h
loc_00941B2E:   If var_474 >= 501 Then GoTo loc_00941B39
loc_00941B37:   GoTo loc_00941B44
loc_00941B39:   'Referenced from: 00941B2E
loc_00941B39:   var_eax = Err.Raise
loc_00941B3E:   var_E34 = Err.Raise
loc_00941B44:   'Referenced from: 00941B37
loc_00941B55:   If var_470 >= 7 Then GoTo loc_00941B60
loc_00941B5E:   GoTo loc_00941B6B
loc_00941B60:   'Referenced from: 00941B55
loc_00941B60:   var_eax = Err.Raise
loc_00941B65:   var_E38 = Err.Raise
loc_00941B6B:   'Referenced from: 00941B5E
loc_00941B7D:   var_478 = var_478 + var_474 * 501
loc_00941BA5:   var_478 = var_1B4
loc_00941BB5:   If var_478 >= 501 Then GoTo loc_00941BC0
loc_00941BBE:   GoTo loc_00941BCB
loc_00941BC0:   'Referenced from: 00941BB5
loc_00941BC0:   var_eax = Err.Raise
loc_00941BC5:   var_E3C = Err.Raise
loc_00941BCB:   'Referenced from: 00941BBE
  loc_00941BDF: var_474 = var_190 + 0002h
loc_00941BEF:   If var_474 >= 501 Then GoTo loc_00941BFA
loc_00941BF8:   GoTo loc_00941C05
loc_00941BFA:   'Referenced from: 00941BEF
loc_00941BFA:   var_eax = Err.Raise
loc_00941BFF:   var_E40 = Err.Raise
loc_00941C05:   'Referenced from: 00941BF8
loc_00941C16:   If var_470 >= 7 Then GoTo loc_00941C21
loc_00941C1F:   GoTo loc_00941C2C
loc_00941C21:   'Referenced from: 00941C16
loc_00941C21:   var_eax = Err.Raise
loc_00941C26:   var_E44 = Err.Raise
loc_00941C2C:   'Referenced from: 00941C1F
loc_00941C3E:   var_478 = var_478 + var_474 * 501
loc_00941C7F:   var_348 = "#####0"
loc_00941C95:   If var_470 >= 7 Then GoTo loc_00941CA0
loc_00941C9E:   GoTo loc_00941CAB
loc_00941CA0:   'Referenced from: 00941C95
loc_00941CA0:   var_eax = Err.Raise
loc_00941CA5:   var_E48 = Err.Raise
loc_00941CAB:   'Referenced from: 00941C9E
loc_00941CBA:   var_3A0 = ecx + eax * 4
loc_00941CE9:   var_150 = Format$(ecx + eax * 4, var_348)
loc_00941D0B:   var_C0 = "Order"
  loc_00941D2C: var_eax = Unknown_VTable_Call[eax+000000B4h]
  loc_00941D34: var_470 = Unknown_VTable_Call[eax+000000B4h]
loc_00941D7F:   var_3A0 = var_C0
loc_00941DB8:   DBEngine.DefaultPassword = var_C0
loc_00941DBD:   var_478 = eax
loc_00941E05:   var_3B0 = var_150
  loc_00941E37: var_eax = DBEngine.CompactDatabase var_150, var_3B4, var_3B0, var_3AC, var_310
  loc_00941E3C: var_480 = DBEngine.CompactDatabase var_150, var_3B4, var_3B0, var_3AC, var_310
loc_00941EB1:   var_348 = "#####0"
loc_00941EC7:   If var_470 >= 7 Then GoTo loc_00941ED2
loc_00941ED0:   GoTo loc_00941EDD
loc_00941ED2:   'Referenced from: 00941EC7
loc_00941ED2:   var_eax = Err.Raise
loc_00941ED7:   var_E58 = Err.Raise
loc_00941EDD:   'Referenced from: 00941ED0
loc_00941EEC:   var_3A0 = ecx + eax * 4
loc_00941F1B:   var_150 = Format$(ecx + eax * 4, var_348)
loc_00941F3D:   var_C0 = "First-Value"
  loc_00941F5E: var_eax = Unknown_VTable_Call[eax+000000B4h]
  loc_00941F66: var_470 = Unknown_VTable_Call[eax+000000B4h]
loc_00941FB1:   var_3A0 = var_C0
loc_00941FEA:   DBEngine.DefaultPassword = var_C0
loc_00941FEF:   var_478 = eax
loc_00942037:   var_3B0 = var_150
  loc_00942069: var_eax = DBEngine.CompactDatabase var_150, var_3B4, var_3B0, var_3AC
  loc_0094206E: var_480 = DBEngine.CompactDatabase var_150, var_3B4, var_3B0, var_3AC
loc_009420E3:   var_348 = "#####0"
loc_009420F9:   If var_470 >= 7 Then GoTo loc_00942104
loc_00942102:   GoTo loc_0094210F
loc_00942104:   'Referenced from: 009420F9
loc_00942104:   var_eax = Err.Raise
loc_00942109:   var_E68 = Err.Raise
loc_0094210F:   'Referenced from: 00942102
loc_0094211E:   var_3A0 = ecx + eax * 4
loc_0094214D:   var_150 = Format$(ecx + eax * 4, var_348)
loc_0094216F:   var_C0 = "Second-Value"
  loc_00942190: var_eax = Unknown_VTable_Call[eax+000000B4h]
  loc_00942198: var_470 = Unknown_VTable_Call[eax+000000B4h]
loc_009421E3:   var_3A0 = var_C0
loc_0094221C:   DBEngine.DefaultPassword = var_C0
loc_00942221:   var_478 = eax
loc_00942269:   var_3B0 = var_150
  loc_0094229B: var_eax = DBEngine.CompactDatabase var_150, var_3B4, var_3B0, var_3AC
  loc_009422A0: var_480 = DBEngine.CompactDatabase var_150, var_3B4, var_3B0, var_3AC
loc_00942307:   If (var_EE0904 = var_006EAF7C) = 0 Then GoTo loc_0094230E
loc_00942309:   GoTo loc_0094292E
loc_0094230E:   'Referenced from: 00942307
loc_0094233A:   var_3A0 = vbNullString
loc_0094236D:   var_150 = Format$(vbNullString, "######.00")
loc_0094238F:   var_C0 = "Seed-Number"
  loc_009423B0: var_eax = Unknown_VTable_Call[eax+000000B4h]
  loc_009423B8: var_470 = Unknown_VTable_Call[eax+000000B4h]
loc_00942403:   var_3A0 = var_C0
loc_0094243C:   DBEngine.DefaultPassword = var_C0
loc_00942441:   var_478 = eax
loc_00942489:   var_3B0 = var_150
  loc_009424BB: var_eax = DBEngine.CompactDatabase var_150, var_3B4, var_3B0, var_3AC
  loc_009424C0: var_480 = DBEngine.CompactDatabase var_150, var_3B4, var_3B0, var_3AC
loc_00942565:   var_150 = Format$(Now, "m/d/yyyy")
loc_00942594:   var_C0 = "Date"
  loc_009425B5: var_eax = Unknown_VTable_Call[eax+000000B4h]
  loc_009425BD: var_470 = Unknown_VTable_Call[eax+000000B4h]
loc_00942608:   var_3A0 = var_C0
loc_00942641:   DBEngine.DefaultPassword = var_C0
loc_00942646:   var_478 = eax
loc_0094268E:   var_3B0 = var_150
  loc_009426C0: var_eax = DBEngine.CompactDatabase var_150, var_3B4, var_3B0, var_3AC
  loc_009426C5: var_480 = DBEngine.CompactDatabase var_150, var_3B4, var_3B0, var_3AC
loc_0094276A:   var_150 = Format$(Now, "hh:mm")
loc_00942799:   var_C0 = "Time"
  loc_009427BA: var_eax = Unknown_VTable_Call[eax+000000B4h]
  loc_009427C2: var_470 = Unknown_VTable_Call[eax+000000B4h]
loc_0094280D:   var_3A0 = var_C0
loc_00942846:   DBEngine.DefaultPassword = var_C0
loc_0094284B:   var_478 = eax
loc_00942893:   var_3B0 = var_150
  loc_009428C5: var_eax = DBEngine.CompactDatabase var_150, var_3B4, var_3B0, var_3AC
  loc_009428CA: var_480 = DBEngine.CompactDatabase var_150, var_3B4, var_3B0, var_3AC
  loc_00942929: ecx = 006EAF94h
loc_0094292E:   'Referenced from: 00942309
  loc_00942947: var_eax = Unknown_VTable_Call[eax+00000164h]
  loc_0094294F: var_470 = Unknown_VTable_Call[eax+00000164h]
  loc_0094299D: var_eax = Unknown_VTable_Call[eax+000000C0h]
  loc_009429A5: var_470 = Unknown_VTable_Call[eax+000000C0h]
loc_009429E5:   GoTo loc_009419AB
loc_009429EA:   'Referenced from: 009419D4
loc_009429F1:   GoTo loc_0094191D
loc_009429F6:   'Referenced from: 00941946
  loc_00942A04: call Return(var_518, var_310, var_310, 00000001h, 00000000h)
loc_00942A09:   'Referenced from: 009397C6
  loc_00942A35: 00000050h = 00000050h - Len("Windows RAT-STATS")
  loc_00942A85: Print 4, CInt()
  loc_00942AB9: 00000050h = 00000050h - Len("Statistical Software")
  loc_00942B09: Print 4, CInt()
loc_00942BB3:   Print 4, "Date: " & Format$(Now, "m/d/yyyy")
loc_00942C07:   Print 4, "Random Number Generator"
loc_00942CAF:   Print 4, "Time: " & Format$(Now, "h:mm")
  loc_00942D27: 00000050h = 00000050h - Len("AUDIT: " & var_EE081C)
  loc_00942D77: Print 4, CInt()
loc_00942D92:   Print 4, vbNullString
loc_00942DAD:   Print 4, "SEED NUMBER: "
loc_00942DE1:   var_3A0 = vbNullString
loc_00942E38:   Print 4, Format$(vbNullString, "#####0.00")
loc_00942E55:   Print 4, 53
loc_00942E89:   var_3A0 = vbNullString
  loc_00942EE1: 0000000Fh = 0000000Fh - Len(Format$(vbNullString, "#,###,###,###"))
loc_00942F0F:   Print 4, 0; Fh
loc_00942F25:   Print 4
loc_00942F3A:   Print 4
loc_00942F5A:   Print 4, "     FILE OF RANDOM NUMBERS: "
loc_00942F70:   Print 4
loc_00942F8A:   Print 4, "     TOTAL RANDOM NUMBERS GENERATED: "
  loc_00942FC4: 00EE085Ch = 00EE085Ch + 00EE085Eh
loc_00943032:   Print 4, Format$(15599708, "##,###")
loc_00943048:   Print 4
loc_00943071:   GoTo loc_0094308E
loc_00943073:
loc_0094307A:   var_1E0 = var_1E0 + 1
loc_00943087:   var_1E0 = var_1E0
loc_0094308E:   'Referenced from: 00943071
loc_0094309C:   If var_1E0 > 0 Then GoTo loc_009435FD
loc_009430B0:   var_470 = var_1E0
loc_009430C0:   If var_470 >= 501 Then GoTo loc_009430CB
loc_009430C9:   GoTo loc_009430D6
loc_009430CB:   'Referenced from: 009430C0
loc_009430CB:   var_eax = Err.Raise
loc_009430D0:   var_EC8 = Err.Raise
loc_009430D6:   'Referenced from: 009430C9
loc_009430E6:   var_508 = ecx + eax * 2
loc_009430FF:   GoTo loc_0094311C
loc_00943101:
loc_00943108:   var_1B4 = var_1B4 + 1
loc_00943115:   var_1B4 = var_1B4
loc_0094311C:   'Referenced from: 009430FF
loc_0094312A:   If var_1B4 > 0 Then GoTo loc_009435F1
  loc_0094313E: var_1E0 = var_1E0 * 0003h
  loc_00943152: var_190 = var_1E0 - 0002h
  loc_00943167: var_2F4 = var_2F4 + 0001h
loc_00943171:   var_2F4 = var_2F4
loc_00943186:   var_478 = var_1B4
loc_00943196:   If var_478 >= 501 Then GoTo loc_009431A1
loc_0094319F:   GoTo loc_009431AC
loc_009431A1:   'Referenced from: 00943196
loc_009431A1:   var_eax = Err.Raise
loc_009431A6:   var_ECC = Err.Raise
loc_009431AC:   'Referenced from: 0094319F
  loc_009431B3: var_474 = var_1E0 - 0002h - 0002h
loc_009431C3:   If var_474 >= 501 Then GoTo loc_009431CE
loc_009431CC:   GoTo loc_009431D9
loc_009431CE:   'Referenced from: 009431C3
loc_009431CE:   var_eax = Err.Raise
loc_009431D3:   var_ED0 = Err.Raise
loc_009431D9:   'Referenced from: 009431CC
loc_009431EA:   If var_470 >= 7 Then GoTo loc_009431F5
loc_009431F3:   GoTo loc_00943200
loc_009431F5:   'Referenced from: 009431EA
loc_009431F5:   var_eax = Err.Raise
loc_009431FA:   var_ED4 = Err.Raise
loc_00943200:   'Referenced from: 009431F3
loc_00943212:   var_478 = var_478 + var_474 * 501
loc_0094323A:   var_478 = var_1B4
loc_0094324A:   If var_478 >= 501 Then GoTo loc_00943255
loc_00943253:   GoTo loc_00943260
loc_00943255:   'Referenced from: 0094324A
loc_00943255:   var_eax = Err.Raise
loc_0094325A:   var_ED8 = Err.Raise
loc_00943260:   'Referenced from: 00943253
  loc_00943267: var_190 = var_190 + 0001h
  loc_00943274: var_474 = var_190 + 0001h
loc_00943284:   If var_474 >= 501 Then GoTo loc_0094328F
loc_0094328D:   GoTo loc_0094329A
loc_0094328F:   'Referenced from: 00943284
loc_0094328F:   var_eax = Err.Raise
loc_00943294:   var_EDC = Err.Raise
loc_0094329A:   'Referenced from: 0094328D
loc_009432AB:   If var_470 >= 7 Then GoTo loc_009432B6
loc_009432B4:   GoTo loc_009432C1
loc_009432B6:   'Referenced from: 009432AB
loc_009432B6:   var_eax = Err.Raise
loc_009432BB:   var_EE0 = Err.Raise
loc_009432C1:   'Referenced from: 009432B4
loc_009432D3:   var_478 = var_478 + var_474 * 501
loc_009432FB:   var_478 = var_1B4
loc_0094330B:   If var_478 >= 501 Then GoTo loc_00943316
loc_00943314:   GoTo loc_00943321
loc_00943316:   'Referenced from: 0094330B
loc_00943316:   var_eax = Err.Raise
loc_0094331B:   var_EE4 = Err.Raise
loc_00943321:   'Referenced from: 00943314
  loc_00943335: var_474 = var_190 + 0002h
loc_00943345:   If var_474 >= 501 Then GoTo loc_00943350
loc_0094334E:   GoTo loc_0094335B
loc_00943350:   'Referenced from: 00943345
loc_00943350:   var_eax = Err.Raise
loc_00943355:   var_EE8 = Err.Raise
loc_0094335B:   'Referenced from: 0094334E
loc_0094336C:   If var_470 >= 7 Then GoTo loc_00943377
loc_00943375:   GoTo loc_00943382
loc_00943377:   'Referenced from: 0094336C
loc_00943377:   var_eax = Err.Raise
loc_0094337C:   var_EEC = Err.Raise
loc_00943382:   'Referenced from: 00943375
loc_00943394:   var_478 = var_478 + var_474 * 501
loc_009433D5:   var_348 = "0000"
loc_009433EB:   If var_470 >= 7 Then GoTo loc_009433F6
loc_009433F4:   GoTo loc_00943401
loc_009433F6:   'Referenced from: 009433EB
loc_009433F6:   var_eax = Err.Raise
loc_009433FB:   var_EF0 = Err.Raise
loc_00943401:   'Referenced from: 009433F4
loc_00943410:   var_3A0 = ecx + eax * 4
loc_00943463:   Print 4, Format$(ecx + eax * 4, var_348)
loc_00943492:   var_348 = "0000000000"
loc_009434A8:   If var_470 >= 7 Then GoTo loc_009434B3
loc_009434B1:   GoTo loc_009434BE
loc_009434B3:   'Referenced from: 009434A8
loc_009434B3:   var_eax = Err.Raise
loc_009434B8:   var_EF4 = Err.Raise
loc_009434BE:   'Referenced from: 009434B1
loc_009434CD:   var_3A0 = ecx + eax * 4
loc_00943520:   Print 4, Format$(ecx + eax * 4, var_348)
loc_0094354F:   var_348 = "0000000000"
loc_00943565:   If var_470 >= 7 Then GoTo loc_00943570
loc_0094356E:   GoTo loc_0094357B
loc_00943570:   'Referenced from: 00943565
loc_00943570:   var_eax = Err.Raise
loc_00943575:   var_EF8 = Err.Raise
loc_0094357B:   'Referenced from: 0094356E
loc_0094358A:   var_3A0 = ecx + eax * 4
loc_009435DD:   Print 4, Format$(ecx + eax * 4, var_348)
loc_009435EC:   GoTo loc_00943101
loc_009435F1:   'Referenced from: 0094312A
loc_009435F8:   GoTo loc_00943073
loc_009435FD:   'Referenced from: 0094309C
  loc_0094360B: call Return(var_518)
loc_00943610:   'Referenced from: 0093317F
  loc_0094364D: var_eax = Unknown_VTable_Call[eax+000000E0h]
  loc_00943655: var_474 = Unknown_VTable_Call[eax+000000E0h]
loc_00943698:   setz al
loc_009436B8:   If var_478 = 0 Then GoTo loc_009436BF
loc_009436BA:   GoTo loc_00944946
loc_009436BF:   'Referenced from: 009436B8
loc_009436CE:   If var_EE085C <= 0 Then GoTo loc_009436D7
loc_009436D0:   GoTo loc_009437D1
loc_009436D5:   GoTo loc_00943709
loc_009436D7:   'Referenced from: 009436CE
loc_009436F0:   If (var_290 <> "OFF") <> 0 Then GoTo loc_00943704
loc_009436FB:   If var_EE085C <> 0 Then GoTo loc_00943704
loc_009436FD:   GoTo loc_009437D1
loc_00943702:   GoTo loc_00943709
loc_00943704:   'Referenced from: 009436F0
loc_00943704:   GoTo loc_00944946
loc_00943709:   'Referenced from: 009436D5
loc_00943718:   If var_EE085C <= 0 Then GoTo loc_009437D1
  loc_0094377B: var_474 = Global.Printer
loc_009437E3:   var_290 = "OFF"
loc_009437FA:   var_1C4 = "Windows RAT-STATS"
  loc_0094380D: var_eax = GoSub var_518
  loc_00943814: If GoSub var_518 <> 0 Then GoTo loc_0094381B
loc_00943816:   GoTo loc_00944965
loc_0094381B:   'Referenced from: 00943814
loc_0094382D:   var_1C4 = "Statistical Software"
  loc_00943840: var_eax = GoSub var_518
  loc_00943847: If GoSub var_518 <> 0 Then GoTo loc_0094384E
loc_00943849:   GoTo loc_00944965
loc_0094384E:   'Referenced from: 00943847
  loc_009438A6: var_328 = Global.Printer
loc_009438AB:   var_474 = var_328
  loc_00943980: call __vbaPrintObj(var_006E89EC, var_328, "Date: " & Format$(Now, "m/d/yyyy"), 0000000Ch, 00000001h, 00000001h, GoSub var_518, Me)
  loc_00943A22: var_328 = Global.Printer
loc_00943A27:   var_474 = var_328
  loc_00943A6F: call __vbaPrintObj(var_006E89EC, var_328, "Random Number Generator", 00000012h)
  loc_00943ADA: var_328 = Global.Printer
loc_00943ADF:   var_474 = var_328
  loc_00943BB2: call __vbaPrintObj(var_006E8DB0, var_328, "Time: " & Format$(Now, "h:mm"), 00000001h, 00000001h)
loc_00943C1B:   var_1C4 = "AUDIT: " & var_EE081C
  loc_00943C2E: var_eax = GoSub var_518
  loc_00943C35: If GoSub var_518 <> 0 Then GoTo loc_00943C3C
loc_00943C37:   GoTo loc_00944965
loc_00943C3C:   'Referenced from: 00943C35
  loc_00943C94: var_328 = Global.Printer
loc_00943C99:   var_474 = var_328
  loc_00943CDF: call __vbaPrintObj(var_006E8DB0, var_328, vbNullString)
  loc_00943D4A: var_328 = Global.Printer
loc_00943D4F:   var_474 = var_328
  loc_00943D95: call __vbaPrintObj(var_006E9114, var_328, "SEED NUMBER: ")
loc_00943DD4:   var_3A0 = vbNullString
loc_00943E07:   var_150 = Format$(vbNullString, "#####0.00")
  loc_00943E6F: var_328 = Global.Printer
loc_00943E74:   var_474 = var_328
  loc_00943EBB: call __vbaPrintObj(var_006E9114, var_328, var_150, 00000001h, 00000001h)
  loc_00943F26: var_328 = Global.Printer
loc_00943F2B:   var_474 = var_328
  loc_00943F73: call __vbaPrintObj(var_006EA3B8, var_328, 00000034h, "FRAME SIZE: ")
loc_00943FB2:   var_3A0 = vbNullString
loc_00943FE5:   var_150 = Format$(vbNullString, "#,###,###,###")
  loc_0094400A: 0000000Fh = 0000000Fh - Len(var_150)
  loc_00944076: var_328 = Global.Printer
loc_0094407B:   var_474 = var_328
  loc_009440C8: call __vbaPrintObj(var_006EA3C4, var_328, var_BC, var_150, 00000001h, 00000001h)
  loc_009440E8: On Error Goto
  loc_009440FB: var_F48 = On Error Goto
loc_00944108:   If var_F48 = 1 Then GoTo loc_0094411A
loc_00944111:   If var_F48 = 2 Then GoTo loc_00944115
loc_00944113:   GoTo loc_0094411A
loc_00944115:   'Referenced from: 00944111
loc_00944115:   GoTo loc_009443D3
loc_0094411A:   'Referenced from: 00944108
  loc_00944172: var_328 = Global.Printer
loc_00944177:   var_474 = var_328
  loc_009441BD: call __vbaPrintObj(var_006E8DB0, var_328, vbNullString, var_14C)
  loc_00944228: var_328 = Global.Printer
loc_0094422D:   var_474 = var_328
  loc_00944275: call __vbaPrintObj(var_006EA3B8, var_328, 00000012h, var_006EAC14)
loc_009442B4:   var_3A0 = vbNullString
loc_009442E7:   var_150 = Format$(vbNullString, "##,###")
  loc_0094434F: var_328 = Global.Printer
loc_00944354:   var_474 = var_328
  loc_009443A2: call __vbaPrintObj(var_006EAFE8, var_328, 00000006h, var_150, " Random Numbers in Sequential Order", 00000001h, 00000001h)
  loc_009443C0: var_54 = var_54 + 0002h
loc_009443CA:   var_54 = var_54
loc_009443CE:   GoTo loc_0094466E
loc_009443D3:   'Referenced from: 00944115
  loc_0094442B: var_328 = Global.Printer
loc_00944430:   var_474 = var_328
  loc_00944476: call __vbaPrintObj(var_006E8DB0, var_328, vbNullString)
  loc_009444E1: var_328 = Global.Printer
loc_009444E6:   var_474 = var_328
  loc_0094452E: call __vbaPrintObj(var_006EA3B8, var_328, 00000012h, var_006EAC14)
loc_0094456D:   var_3A0 = vbNullString
loc_009445A0:   var_150 = Format$(vbNullString, "##,###")
  loc_00944608: var_328 = Global.Printer
loc_0094460D:   var_474 = var_328
  loc_0094465B: call __vbaPrintObj(var_006EAFE8, var_328, 00000006h, var_150, " Random Numbers in Generated Order", 00000001h, 00000001h)
loc_0094466E:   'Referenced from: 009443CE
  loc_009446C6: var_328 = Global.Printer
loc_009446CB:   var_474 = var_328
  loc_00944711: call __vbaPrintObj(var_006E8DB0, var_328, vbNullString)
  loc_0094477C: var_328 = Global.Printer
loc_00944781:   var_474 = var_328
  loc_009447C7: call __vbaPrintObj(var_006E8DB0, var_328, " ORDER OF                               ORDER OF")
  loc_00944832: var_328 = Global.Printer
loc_00944837:   var_474 = var_328
  loc_0094487D: call __vbaPrintObj(var_006E8DB0, var_328, "SELECTION    FIRST NBR.  SECOND NBR.   SELECTION    FIRST NBR.   SECOND NBR.")
  loc_009448E8: var_328 = Global.Printer
loc_009448ED:   var_474 = var_328
  loc_00944933: call __vbaPrintObj(var_006E8DB0, var_328, vbNullString)
loc_00944946:   'Referenced from: 009436BA
  loc_00944960: call Return(var_518)
loc_00944965:   'Referenced from: 00943816
  loc_0094497A: 00000050h = 00000050h - Len(var_1C4)
  loc_009449AF: var_3C = CInt()
  loc_00944A0B: var_328 = Global.Printer
loc_00944A10:   var_474 = var_328
  loc_00944A5A: call __vbaPrintObj(var_006E8B84, var_328, var_3C, var_1C4)
  loc_00944A7B: call Return(var_518)
loc_00944A80:   'Referenced from: 00933361
  loc_00944ABD: var_eax = Unknown_VTable_Call[eax+000000E0h]
  loc_00944AC5: var_474 = Unknown_VTable_Call[eax+000000E0h]
loc_00944B08:   setz al
loc_00944B28:   If var_478 = 0 Then GoTo loc_00944F14
  loc_00944B55: var_50 = var_54 + 0001h
loc_00944B59:   GoTo loc_00944B70
loc_00944B5B:
loc_00944B5F:   var_50 = var_50 + 1
loc_00944B6C:   var_50 = var_50
loc_00944B70:   'Referenced from: 00944B59
loc_00944B7B:   If var_50 > 0 Then GoTo loc_00944C43
loc_00944BBE:   var_470 = eax
  loc_00944BD9: var_328 = Global.Printer
loc_00944BDE:   var_474 = var_328
  loc_00944C24: call __vbaPrintObj(var_006E8DB0, var_328, vbNullString, var_470, var_42C, var_328, var_474, Me)
loc_00944C3E:   GoTo loc_00944B5B
loc_00944C43:   'Referenced from: 00944B7B
  loc_00944C9B: var_328 = Global.Printer
loc_00944CA0:   var_474 = var_328
  loc_00944CE3: call __vbaPrintObj(var_006EB0DC, var_328, 00000046h)
loc_00944D28:   var_3A0 = var_114
loc_00944D57:   var_150 = Format$(var_114, "##")
  loc_00944DBF: var_328 = Global.Printer
loc_00944DC4:   var_474 = var_328
  loc_00944E10: call __vbaPrintObj(var_006EA410, var_328, "Page: ", var_150, 00000001h, 00000001h)
  loc_00944E31: var_114 = var_114 + 0001h
loc_00944E3B:   var_114 = var_114
loc_00944E5B:   If (var_B8 <> "NO") <> 0 Then GoTo loc_00944F14
  loc_00944EB9: var_328 = Global.Printer
loc_00944EBE:   var_474 = var_328
  loc_00944F22: call Return(var_518)
loc_00944F27:   'Referenced from: 00931FD3
loc_00944F9B:   frmFileNames.Text1.Text = vbNullString
loc_00944FA3:   var_474 = eax
loc_0094505B:   frmFileNames.Text2.Text = vbNullString
loc_00945063:   var_474 = eax
loc_0094511B:   frmFileNames.Text3.Text = vbNullString
loc_00945123:   var_474 = eax
loc_009451DB:   frmFileNames.Text4.Text = vbNullString
loc_009451E3:   var_474 = eax
loc_0094529B:   frmFileNames.Text5.Text = vbNullString
loc_009452A3:   var_474 = eax
loc_0094535B:   frmFileNames.Text6.Text = vbNullString
loc_00945363:   var_474 = eax
loc_009453A7:   GoTo loc_009458DB
  loc_00945404: var_328 = Global.Screen
loc_00945409:   var_474 = var_328
  loc_00945462: Global.MousePointer = 00000001h
loc_00945467:   var_47C = eax
loc_0094550B:   var_348 = "The program cannot open your output text file."
loc_00945559:   GoTo loc_009458DB
  loc_009455B6: var_328 = Global.Screen
loc_009455BB:   var_474 = var_328
  loc_00945614: Global.MousePointer = 00000001h
loc_00945619:   var_47C = eax
loc_009456BD:   var_348 = "The program cannot output the results to your output text file."
loc_0094570B:   GoTo loc_009458DB
  loc_00945768: var_328 = Global.Screen
loc_0094576D:   var_474 = var_328
  loc_009457C6: Global.MousePointer = 00000001h
loc_009457CB:   var_47C = eax
loc_0094586F:   var_348 = "The program cannot open your output flat file."
loc_009458BD:   GoTo loc_009458DB
loc_009458C8:   On Error Resume Next
loc_009458D6:   Close #3
loc_009458DB:   'Referenced from: 0092F8E4
loc_009458DB:   Exit Sub
loc_009458E6:   GoTo loc_0094596C
loc_0094596B:   Exit Sub
loc_0094596C:   'Referenced from: 009458E6
loc_009459CA:   var_440 = var_8C
loc_009459E4:   var_444 = var_A8
loc_00945A14:   var_448 = var_D8
loc_00945A2E:   var_44C = var_FC
loc_00945A7F:   var_450 = var_134
loc_00945ABA:   var_454 = var_16C
loc_00945AD4:   var_458 = var_188
loc_00945AEE:   var_45C = var_1AC
loc_00945B4A:   var_460 = var_228
loc_00945B64:   var_464 = var_25C
loc_00945B7E:   var_468 = var_278
loc_00945BCF:   var_46C = var_2E8
  loc_00945C21: call __vbaGosubFree(var_518, var_518, var_328)
loc_00945C26:   Exit Sub
  loc_00945C2F: var_eax = Unknown_VTable_Call[eax+00000008h]
loc_00945C42:   leaved
End Sub

Public Sub Proc_8_33_946909()
  loc_0094695B: var_eax = Unknown_VTable_Call[eax+0000009Ch]
  loc_00946963: var_1C = Unknown_VTable_Call[eax+0000009Ch]
loc_009469B7:   txtseed.Visible = True
loc_009469BF:   var_1C = eax
loc_009469EE:   Method_8964F04D
loc_009469F3:   GoTo loc_009469FE
loc_009469FD:   Exit Sub
loc_009469FE:   'Referenced from: 009469F3
End Sub

Public Sub Proc_8_34_946A12()
  loc_00946A64: var_eax = Unknown_VTable_Call[eax+0000009Ch]
  loc_00946A6C: var_1C = Unknown_VTable_Call[eax+0000009Ch]
loc_00946AC0:   txtseed.Visible = False
loc_00946AC8:   var_1C = eax
loc_00946AF7:   Method_8964F04D
loc_00946AFC:   GoTo loc_00946B07
loc_00946B06:   Exit Sub
loc_00946B07:   'Referenced from: 00946AFC
End Sub

Public Sub Proc_8_35_946B1B()
  loc_00946B6D: call __vbaVarLateMemSt(var_20, "Visible", 11, var_4C, var_48, var_44, ecx, ecx, @stk@FFFC)
  loc_00946B97: call __vbaVarLateMemSt
  loc_00946BC1: call __vbaVarLateMemSt(var_30, "Visible", 11, var_4C, var_48, var_44)
loc_00946BC6:   Method_8964F04D
End Sub

Public Sub Proc_8_36_946BF7()
  loc_00946C49: call __vbaVarLateMemSt(var_40, "Visible", 11, var_4C, var_48, var_44, ecx, ecx, @stk@FFFC)
  loc_00946C73: call __vbaVarLateMemSt
  loc_00946C9D: call __vbaVarLateMemSt(var_20, "Visible", 11, var_4C, var_48, var_44)
loc_00946CA2:   Method_8964F04D
End Sub
