function setConfig(data) {
  debugger
}

function loadCurrentConfig() {
  $.get("/config.json", {
    success: setConfig
  })
}

$(document).on("ready", function() {
  
})
