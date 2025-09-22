function doGet(e) {
  var data = e.parameter.data;
  var sheet = SpreadsheetApp.getActiveSpreadsheet().getActiveSheet();
  sheet.getRange("A1").setValue(data);
}