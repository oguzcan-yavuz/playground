/*
*/


function convertHTML(str) {
  var regs = /[&<>"']/g;
  // &colon;&rpar; :)
  for (var i = 0; i < str.length; i++) {
    if (regs.test(str[i])) {
      switch (str[i]) {
        case "&":
          str = str.replace(str[i], "&amp;");
          break;
        case "<":
          str = str.replace(str[i], "&lt;");
          break;
        case ">":
          str = str.replace(str[i], "&gt;");
          break;
        case '"':
          str = str.replace(str[i], "&quot;");
          break;
        case "'":
          str = str.replace(str[i], "&apos;");
          break;
      }
    }
  }
  return str;
}

convertHTML('Stuff in "quotation marks"');

