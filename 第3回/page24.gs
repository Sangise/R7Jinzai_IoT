function doGet(e) {
  var data1 = e.parameter.data1;
  var data2 = e.parameter.data2;
  const ts = Utilities.formatDate(new Date(), 'Asia/Tokyo', 'yyyy-MM-dd HH:mm:ss');
  
  var sheet = SpreadsheetApp.getActiveSpreadsheet().getActiveSheet();
  
  sheet.appendRow([ts, data1, data2]);
}