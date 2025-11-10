// IP cust --- INSERT

// --- expand state management
function minimize() {
	// change container heights
	getCrdwnd().changeHeight("Config", 30);
	doc.getElementById("tdSide").setAttribute("height", "30");
	doc.getElementById("Config_side").setAttribute("height", "30");
	doc.getElementById("Config_cont").setAttribute("height", "30");

	// change content
	doc.getElementById("Config_side").src = "./PnlWzskHwcConfig_aside.html";
	doc.getElementById("Config_cont").src = "./PnlWzskHwcConfig_a.html";
};

function regularize() {
	// change content (container heights in refreshBD)
	doc.getElementById("Config_side").src = "./PnlWzskHwcConfig_bside.html";
	doc.getElementById("Config_cont").src = "./PnlWzskHwcConfig_b.html";
};

// --- view initialization and refresh
function initA() {
	if (!doc) return;

	sidedoc = doc.getElementById("Config_side").contentDocument;
	contdoc = doc.getElementById("Config_cont").contentDocument;
	hdrdoc = null;
	contcontdoc = null;
	ftrdoc = null;

	initCpt(contdoc, "Cpt", retrieveTi(srcdoc, "TagWzskHwcConfig", "Cpt"));

	refreshA();
};

function initBD(bNotD) {
	if (!doc) return;

	sidedoc = doc.getElementById("Config_side").contentDocument;
	contdoc = doc.getElementById("Config_cont").contentDocument;
	hdrdoc = contdoc.getElementById("Config_hdr").contentDocument;
	contcontdoc = contdoc.getElementById("Config_cont").contentDocument;

	// IP initBD --- BEGIN
	initCpt(hdrdoc, "Cpt", retrieveTi(srcdoc, "TagWzskHwcConfig", "Cpt"));
	initCpt(contcontdoc, "HdgPvw", retrieveTi(srcdoc, "TagWzskHwcConfig", "HdgPvw"));
	initCpt(contcontdoc, "CptMde", retrieveTi(srcdoc, "TagWzskHwcConfig", "CptMde"));
	refreshRbu(contcontdoc, srcdoc, "RbuMde", "FeedFRbuMde", retrieveCi(srcdoc, "ContIacWzskHwcConfig", "numFRbuMde"), retrieveSi(srcdoc, "StatShrWzskHwcConfig", "RbuMdeActive"));
	initCpt(contcontdoc, "CptNfr", retrieveTi(srcdoc, "TagWzskHwcConfig", "CptNfr"));
	initCpt(contcontdoc, "CptFst", retrieveTi(srcdoc, "TagWzskHwcConfig", "CptFst"));
	initCpt(contcontdoc, "CptFsp", retrieveTi(srcdoc, "TagWzskHwcConfig", "CptFsp"));
	initCpt(contcontdoc, "CptSte", retrieveTi(srcdoc, "TagWzskHwcConfig", "CptSte"));
	initBut(contcontdoc, "ButSta", retrieveTi(srcdoc, "TagWzskHwcConfig", "ButSta"));
	initBut(contcontdoc, "ButSto", retrieveTi(srcdoc, "TagWzskHwcConfig", "ButSto"));
	// IP initBD --- END

	refreshBD(bNotD);
};

function init() {
	var srefIxWzskVExpstate = retrieveSi(srcdoc, "StatShrWzskHwcConfig", "srefIxWzskVExpstate");

	if (srefIxWzskVExpstate == "mind") {
		initA();
	} else if (srefIxWzskVExpstate == "regd") {
		initBD(true);
	} else if (srefIxWzskVExpstate == "detd") {
		initBD(false);
	};
};

function refreshA() {
};

function refreshBD(bNotD) {
	if (!contcontdoc) return;

	var height = 583; // full cont height

	// IP refreshBD.vars --- BEGIN
	var ButClaimActive = (retrieveSi(srcdoc, "StatShrWzskHwcConfig", "ButClaimActive") == "true");

	var RbuMdeActive = (retrieveSi(srcdoc, "StatShrWzskHwcConfig", "RbuMdeActive") == "true");

	var CusImgHeight = parseInt(retrieveSi(srcdoc, "StatShrWzskHwcConfig", "CusImgHeight"));

	var UpdNfrActive = (retrieveSi(srcdoc, "StatShrWzskHwcConfig", "UpdNfrActive") == "true");

	var SldFstActive = (retrieveSi(srcdoc, "StatShrWzskHwcConfig", "SldFstActive") == "true");

	var SldFspActive = (retrieveSi(srcdoc, "StatShrWzskHwcConfig", "SldFspActive") == "true");

	var ButStaActive = (retrieveSi(srcdoc, "StatShrWzskHwcConfig", "ButStaActive") == "true");
	var ButStoActive = (retrieveSi(srcdoc, "StatShrWzskHwcConfig", "ButStoActive") == "true");

	// IP refreshBD.vars --- END

	// IP refreshBD --- BEGIN
	refreshButicon(hdrdoc, "ButClaim", "icon/claim", ButClaimActive, retrieveCi(srcdoc, "ContInfWzskHwcConfig", "ButClaimOn") == "true");

	setRbuValue(contcontdoc, "RbuMde", retrieveCi(srcdoc, "ContIacWzskHwcConfig", "numFRbuMde"), RbuMdeActive);

	mytd = contcontdoc.getElementById("tdImg");
	mytd.setAttribute("height", "" + CusImgHeight);
	contcontdoc.getElementById("CusImg").setAttribute("height", "" + CusImgHeight);
	height += CusImgHeight-384;

	refreshUpd(contcontdoc, "UpdNfr", parseInt(retrieveSi(srcdoc, "StatShrWzskHwcConfig", "UpdNfrMin")), parseInt(retrieveSi(srcdoc, "StatShrWzskHwcConfig", "UpdNfrMax")), parseInt(retrieveCi(srcdoc, "ContIacWzskHwcConfig", "UpdNfr")), UpdNfrActive, false);

	refreshSld(contcontdoc, "SldFst", true, false, parseFloat(retrieveSi(srcdoc, "StatShrWzskHwcConfig", "SldFstMin")), parseFloat(retrieveSi(srcdoc, "StatShrWzskHwcConfig", "SldFstMax")), parseFloat(retrieveCi(srcdoc, "ContIacWzskHwcConfig", "SldFst")), SldFstActive, false);

	refreshSld(contcontdoc, "SldFsp", true, false, parseFloat(retrieveSi(srcdoc, "StatShrWzskHwcConfig", "SldFspMin")), parseFloat(retrieveSi(srcdoc, "StatShrWzskHwcConfig", "SldFspMax")), parseFloat(retrieveCi(srcdoc, "ContIacWzskHwcConfig", "SldFsp")), SldFspActive, false);

	refreshTxt(contcontdoc, "TxtSte", retrieveCi(srcdoc, "ContInfWzskHwcConfig", "TxtSte"));

	refreshBut(contcontdoc, "ButSta", ButStaActive, false);
	refreshBut(contcontdoc, "ButSto", ButStoActive, false);

	// IP refreshBD --- END

	getCrdwnd().changeHeight("Config", height+31);
	doc.getElementById("tdSide").setAttribute("height", "" + (height+31));
	doc.getElementById("Config_side").setAttribute("height", "" + (height+31));
	doc.getElementById("Config_cont").setAttribute("height", "" + (height+31));
	sidedoc.getElementById("tdFlex").setAttribute("height", "" + (height+31-30));
	contdoc.getElementById("tdCont").setAttribute("height", "" + height);
	contdoc.getElementById("Config_cont").setAttribute("height", "" + height);
};

function refresh() {
	var srefIxWzskVExpstate = retrieveSi(srcdoc, "StatShrWzskHwcConfig", "srefIxWzskVExpstate");

	if (srefIxWzskVExpstate == "mind") {
		refreshA();
	} else if (srefIxWzskVExpstate == "regd") {
		refreshBD(true);
	} else if (srefIxWzskVExpstate == "detd") {
		refreshBD(false);
	};
};

// --- event handlers
function handleLoad() {
	scrJref = location.search.substr(location.search.indexOf("scrJref=")+8);

	doc = document;
	srcdoc = doc.getElementById("Config_src").contentDocument;

	var str = serializeDpchApp("DpchAppWzskInit", scrJref);
	sendReq(str, doc, handleDpchAppInitReply, true);
};

// --- specific event handlers for app controls

function handleCusImgLoad(cusdoc) {
	// IP handleCusImgLoad --- INSERT
};

// --- generalized event handlers for app controls

// --- generalized event handlers for shared controls

function handleButClick(ctlsref) {
	var str = serializeDpchAppDo(srcdoc, "DpchAppWzskHwcConfigDo", scrJref, ctlsref + "Click");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

function handleRbuSelect(_doc, ctlsref, num) {
	setCi(srcdoc, "ContIacWzskHwcConfig", "numF" + ctlsref, "" + num);

	var str = serializeDpchAppData(srcdoc, "DpchAppWzskHwcConfigData", scrJref, "ContIacWzskHwcConfig");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

function handleSldJpleftMov(_doc, ctlsref) {
	if (_doc.getElementById("td" + ctlsref).onmousemove == null) {
		_doc.getElementById(ctlsref + "Jpleftl").setAttribute("class", "sldlhlt");
	};
};

function handleSldJpleftMou(_doc, ctlsref) {
	_doc.getElementById(ctlsref + "Jpleftl").setAttribute("class", "sldl");
};

function handleSldJpleftClick(_doc, ctlsref, shr, log, _rast, evt) {
	var pos, oldVal, val;

	var min, max, rast;

	if (shr) oldVal = parseFloat(retrieveCi(srcdoc, "ContIacWzskHwcConfig", ctlsref));
	else oldVal = parseFloat(_doc.getElementById(ctlsref + "Val").value);
	min = parseFloat(retrieveSi(srcdoc, "StatShrWzskHwcConfig", ctlsref + "Min"));
	max = parseFloat(retrieveSi(srcdoc, "StatShrWzskHwcConfig", ctlsref + "Max"));

	if (_rast) rast = parseFloat(retrieveSi(srcdoc, "StatShrWzskHwcConfig", ctlsref + "Rast"));

	if (_rast) {
		if (log) val = oldVal / rast;
		else val = oldVal - rast;

		if (val < min) val = min;
		if (val > max) val = max;

	} else {
		pos = getSldPosFromEvtx(true, evt.clientX);
		val = getSldValFromPos(min, max, rast, pos);
	};

	pos = getSldPosFromVal(min, max, val);

	setSldPos(_doc, ctlsref, true, pos);
	setSldVal(_doc, ctlsref, val, true, true);

	if (shr) {
		setCi(srcdoc, "ContIacWzskHwcConfig", ctlsref, "" + val);

		var str = serializeDpchAppData(srcdoc, "DpchAppWzskHwcConfigData", scrJref, "ContIacWzskHwcConfig");
		sendReq(str, doc, handleDpchAppDataDoReply);

	} else {
		window["handle" + ctlsref + "Change"](val);
	};
};

function handleSldJprightMov(_doc, ctlsref) {
	if (_doc.getElementById("td" + ctlsref).onmousemove == null) {
		_doc.getElementById(ctlsref + "Jprightl").setAttribute("class", "sldlhlt");
	};
};

function handleSldJprightMou(_doc, ctlsref) {
	_doc.getElementById(ctlsref + "Jprightl").setAttribute("class", "sldl");
};

function handleSldJprightClick(_doc, ctlsref, shr, log, _rast, evt) {
	var pos, oldVal, val;

	var min, max, rast;

	if (shr) oldVal = parseFloat(retrieveCi(srcdoc, "ContIacWzskHwcConfig", ctlsref));
	else oldVal = parseFloat(_doc.getElementById(ctlsref + "Val").value);
	min = parseFloat(retrieveSi(srcdoc, "StatShrWzskHwcConfig", ctlsref + "Min"));
	max = parseFloat(retrieveSi(srcdoc, "StatShrWzskHwcConfig", ctlsref + "Max"));

	if (_rast) rast = parseFloat(retrieveSi(srcdoc, "StatShrWzskHwcConfig", ctlsref + "Rast"));

	if (_rast) {
		if (log) val = oldVal * rast;
		else val = oldVal + rast;

		if (val < min) val = min;
		if (val > max) val = max;

	} else {
		pos = getSldPosFromEvtx(true, evt.clientX);
		val = getSldValFromPos(min, max, rast, pos);
	};

	pos = getSldPosFromVal(min, max, val);

	setSldPos(_doc, ctlsref, true, pos);
	setSldVal(_doc, ctlsref, val, true, true);

	if (shr) {
		setCi(srcdoc, "ContIacWzskHwcConfig", ctlsref, "" + val);

		var str = serializeDpchAppData(srcdoc, "DpchAppWzskHwcConfigData", scrJref, "ContIacWzskHwcConfig");
		sendReq(str, doc, handleDpchAppDataDoReply);

	} else {
		window["handle" + ctlsref + "Change"](val);
	};
};

function handleSldMov(_doc, ctlsref) {
	_doc.getElementById(ctlsref + "Bar").setAttribute("class", "sldlhlt");
};

function handleSldMou(_doc, ctlsref) {
	if (_doc.getElementById("td" + ctlsref).onmousemove == null) {
		_doc.getElementById(ctlsref + "Bar").setAttribute("class", "sldl");
	};
};

function handleSldMdn(_doc, ctlsref) {
	_doc.getElementById("td" + ctlsref).setAttribute("onmousemove", "handle" + ctlsref + "Move(event)");
	_doc.getElementById("td" + ctlsref).setAttribute("onmouseup", "handle" + ctlsref + "Mup(event)");
};

function handleSldMove(_doc, ctlsref, shr, log, _rast, evt) {
	var pos, val;

	var min, max, rast;

	min = parseFloat(retrieveSi(srcdoc, "StatShrWzskHwcConfig", ctlsref + "Min"));
	max = parseFloat(retrieveSi(srcdoc, "StatShrWzskHwcConfig", ctlsref + "Max"));

	if (_rast) rast = parseFloat(retrieveSi(srcdoc, "StatShrWzskHwcConfig", ctlsref + "Rast"));
	else rast = 0.0;

	pos = getSldPosFromEvtx(true, evt.clientX);

	if (log) val = getSldLogvalFromPos(min, max, rast, pos);
	else val = getSldValFromPos(min, max, rast, pos);

	setSldPos(_doc, ctlsref, true, pos);
	setSldVal(_doc, ctlsref, val, true, true);

	if (shr) setCi(srcdoc, "ContIacWzskHwcConfig", ctlsref, "" + val);
	else window["handle" + ctlsref + "Change"](val);
};

function handleSldMup(_doc, ctlsref, shr) {
	_doc.getElementById("td" + ctlsref).onmousemove = null;
	_doc.getElementById("td" + ctlsref).onmouseup = null;

	if (shr) {
		var str = serializeDpchAppData(srcdoc, "DpchAppWzskHwcConfigData", scrJref, "ContIacWzskHwcConfig");
		sendReq(str, doc, handleDpchAppDataDoReply);
	};
};

function handleSldValKey(_doc, ctlsref, shr, log, _rast, evt) {
	var elem = _doc.getElementById(ctlsref + "Val");

	var pos, val;

	var min, max, rast;

	elem.setAttribute("class", "txfxsmod");

	if (evt.keyCode == 13) {
		min = parseFloat(retrieveSi(srcdoc, "StatShrWzskHwcConfig", ctlsref + "Min"));
		max = parseFloat(retrieveSi(srcdoc, "StatShrWzskHwcConfig", ctlsref + "Max"));

		if (_rast) rast = parseFloat(retrieveSi(srcdoc, "StatShrWzskHwcConfig", ctlsref + "Rast"));
		else rast = 0.0;

		val = parseFloat(elem.value);
		if (isNaN(val)) val = 0.0;

		if (log) {
			val = alignSldLogval(min, max, rast, val);
			pos = getSldPosFromLogval(min, max, val);
		} else {
			val = alignSldVal(min, max, rast, val);
			pos = getSldPosFromVal(min, max, val);
		};

		setSldPos(_doc, ctlsref, true, pos);
		setSldVal(_doc, ctlsref, val, true, true);

		if (shr) {
			setCi(srcdoc, "ContIacWzskHwcConfig", ctlsref, "" + val);

			var str = serializeDpchAppData(srcdoc, "DpchAppWzskHwcConfigData", scrJref, "ContIacWzskHwcConfig");
			sendReq(str, doc, handleDpchAppDataDoReply);

		} else {
			window["handle" + ctlsref + "Change"](val);
		};

		return false;
	};

	return true;
};

function handleSldValChange(_doc, ctlsref, shr, log, _rast) {
	var elem = _doc.getElementById(ctlsref + "Val");

	var pos, val;

	var min, max, rast;

	elem.setAttribute("class", "txfxsmod");

	min = parseFloat(retrieveSi(srcdoc, "StatShrWzskHwcConfig", ctlsref + "Min"));
	max = parseFloat(retrieveSi(srcdoc, "StatShrWzskHwcConfig", ctlsref + "Max"));

	if (_rast) rast = parseFloat(retrieveSi(srcdoc, "StatShrWzskHwcConfig", ctlsref + "Rast"));
	else rast = 0.0;

	val = parseFloat(elem.value);
	if (isNaN(val)) val = 0.0;

	if (log) {
		val = alignSldLogval(min, max, rast, val);
		pos = getSldPosFromLogval(min, max, val);
	} else {
		val = alignSldVal(min, max, rast, val);
		pos = getSldPosFromVal(min, max, val);
	};

	setSldPos(_doc, ctlsref, true, pos);
	setSldVal(_doc, ctlsref, val, true, true);

	if (shr) {
		setCi(srcdoc, "ContIacWzskHwcConfig", ctlsref, "" + val);

		var str = serializeDpchAppData(srcdoc, "DpchAppWzskHwcConfigData", scrJref, "ContIacWzskHwcConfig");
		sendReq(str, doc, handleDpchAppDataDoReply);

	} else {
	window["handle" + ctlsref + "Change"](val);
	};
};

function handleUpdValKey(_doc, ctlsref, shr, evt) {
	var elem = _doc.getElementById(ctlsref + "Val");

	var val;

	var min, max;

	elem.setAttribute("class", "txfsmod");

	if (evt.keyCode == 13) {
		min = parseInt(retrieveSi(srcdoc, "StatShrWzskHwcConfig", ctlsref + "Min"));
		max = parseInt(retrieveSi(srcdoc, "StatShrWzskHwcConfig", ctlsref + "Max"));

		val = parseInt(elem.value);
		if (isNaN(val)) val = 0;
		if (val < min) val = min;
		if (val > max) val = max;

		refreshUpd(_doc, ctlsref, min, max, val, true, true);

		if (shr) {
			setCi(srcdoc, "ContIacWzskHwcConfig", ctlsref, "" + val);

			var str = serializeDpchAppData(srcdoc, "DpchAppWzskHwcConfigData", scrJref, "ContIacWzskHwcConfig");
			sendReq(str, doc, handleDpchAppDataDoReply);

		} else {
			window["handle" + ctlsref + "Change"](val);
		};

		return false;
	};

	return true;
};

function handleUpdValChange(_doc, ctlsref, shr) {
	var elem = _doc.getElementById(ctlsref + "Val");

	var val;

	var min, max;

	elem.setAttribute("class", "txfsmod");

	min = parseInt(retrieveSi(srcdoc, "StatShrWzskHwcConfig", ctlsref + "Min"));
	max = parseInt(retrieveSi(srcdoc, "StatShrWzskHwcConfig", ctlsref + "Max"));

	val = parseInt(elem.value);
	if (isNaN(val)) val = 0;
	if (val < min) val = min;
	if (val > max) val = max;

	refreshUpd(_doc, ctlsref, min, max, val, true, true);

	if (shr) {
		setCi(srcdoc, "ContIacWzskHwcConfig", ctlsref, "" + val);

			var str = serializeDpchAppData(srcdoc, "DpchAppWzskHwcConfigData", scrJref, "ContIacWzskHwcConfig");
		setCi(srcdoc, "ContIacWzskHwcConfig", ctlsref, "" + val);
		sendReq(str, doc, handleDpchAppDataDoReply);

	} else {
		window["handle" + ctlsref + "Change"](val);
	};
};

function handleUpdUpClick(_doc, ctlsref, shr) {
	var oldVal, val;

	var min, max;

	if (shr) oldVal = parseInt(retrieveCi(srcdoc, "ContIacWzskHwcConfig", ctlsref));
	else oldVal = parseInt(_doc.getElementById(ctlsref + "Val").value);
	min = parseInt(retrieveSi(srcdoc, "StatShrWzskHwcConfig", ctlsref + "Min"));
	max = parseInt(retrieveSi(srcdoc, "StatShrWzskHwcConfig", ctlsref + "Max"));

	val = oldVal + 1;
	if (val < min) val = min;
	if (val > max) val = max;

	refreshUpd(_doc, ctlsref, min, max, val, true, true);

	if (shr) {
		setCi(srcdoc, "ContIacWzskHwcConfig", ctlsref, "" + val);

		var str = serializeDpchAppData(srcdoc, "DpchAppWzskHwcConfigData", scrJref, "ContIacWzskHwcConfig");
		sendReq(str, doc, handleDpchAppDataDoReply);

	} else {
		window["handle" + ctlsref + "Change"](val);
	};
};

function handleUpdDownClick(_doc, ctlsref, shr) {
	var oldVal, val;

	var min, max;

	if (shr) oldVal = parseInt(retrieveCi(srcdoc, "ContIacWzskHwcConfig", ctlsref));
	else oldVal = parseInt(_doc.getElementById(ctlsref + "Val").value);
	min = parseInt(retrieveSi(srcdoc, "StatShrWzskHwcConfig", ctlsref + "Min"));
	max = parseInt(retrieveSi(srcdoc, "StatShrWzskHwcConfig", ctlsref + "Max"));

	val = oldVal - 1;
	if (val < min) val = min;
	if (val > max) val = max;

	refreshUpd(_doc, ctlsref, min, max, val, true, true);

	if (shr) {
		setCi(srcdoc, "ContIacWzskHwcConfig", ctlsref, "" + val);

		var str = serializeDpchAppData(srcdoc, "DpchAppWzskHwcConfigData", scrJref, "ContIacWzskHwcConfig");
		sendReq(str, doc, handleDpchAppDataDoReply);

	} else {
		window["handle" + ctlsref + "Change"](val);
	};
};

// --- server interaction
function mergeDpchEngData(dom) {
	var mask = [];

	// IP mergeDpchEngData --- BEGIN
	if (updateSrcblock(dom, "DpchEngWzskHwcConfigData", "ContIacWzskHwcConfig", srcdoc)) mask.push("contiac");
	if (updateSrcblock(dom, "DpchEngWzskHwcConfigData", "ContInfWzskHwcConfig", srcdoc)) mask.push("continf");
	if (updateSrcblock(dom, "DpchEngWzskHwcConfigData", "FeedFRbuMde", srcdoc)) mask.push("feedFRbuMde");
	if (updateSrcblock(dom, "DpchEngWzskHwcConfigData", "StatShrWzskHwcConfig", srcdoc)) mask.push("statshr");
	if (updateSrcblock(dom, "DpchEngWzskHwcConfigData", "TagWzskHwcConfig", srcdoc)) mask.push("tag");
	// IP mergeDpchEngData --- END

	return mask;
};

function handleDpchEng(dom, dpch) {
	if (dpch == "DpchEngWzskHwcConfigData") {
		var oldSrefIxWzskVExpstate = retrieveSi(srcdoc, "StatShrWzskHwcConfig", "srefIxWzskVExpstate");

		var mask = mergeDpchEngData(dom);

		if (mask.indexOf("statshr") != -1) {
			var srefIxWzskVExpstate = retrieveSi(srcdoc, "StatShrWzskHwcConfig", "srefIxWzskVExpstate");

			if (srefIxWzskVExpstate != oldSrefIxWzskVExpstate) {
				if (srefIxWzskVExpstate == "mind") minimize();
				else if (srefIxWzskVExpstate == "regd") regularize();
			} else {
				refresh();
			};

		} else {
			refresh();
		};
	} else if (dpch == "DpchEngWzskHwcConfigAlign") {
		handleDpchEngWzskHwcConfigAlign(dom);
	} else if (dpch == "DpchEngWzskHwcConfigLive") {
		handleDpchEngWzskHwcConfigLive(dom);
	};
};

function handleDpchEngWzskHwcConfigAlign(dom) {
	// IP handleDpchEngWzskHwcConfigAlign --- INSERT
};

function handleDpchEngWzskHwcConfigLive(dom) {
	// IP handleDpchEngWzskHwcConfigLive --- INSERT
};

function handleDpchAppInitReply() {
	var dom, blk;

	if (doc.req.readyState == 4) {
		dom = doc.req.responseXML;

		blk = retrieveBlock(dom, "//wzsk:*");
		if (blk) {
			if (blk.nodeName == "DpchEngWzskHwcConfigData") {
				mergeDpchEngData(dom);
				init();

				getCrdwnd().setInitdone("Config");
			};
		};
	};
};

function handleDpchAppDataDoReply() {
	var dom, blk;

	if (doc.req.readyState == 4) {
		dom = doc.req.responseXML;

		// check dispatch type
		blk = retrieveBlock(dom, "//wzsk:*");

		if (blk) {
			if (blk.nodeName == "DpchEngWzskConfirm") {
				// do nothing

			} else if (blk.nodeName == "DpchEngWzskHwcConfigData") {
				var oldSrefIxWzskVExpstate = retrieveSi(srcdoc, "StatShrWzskHwcConfig", "srefIxWzskVExpstate");

				var mask = mergeDpchEngData(dom);

				if (mask.indexOf("statshr") != -1) {
					var srefIxWzskVExpstate = retrieveSi(srcdoc, "StatShrWzskHwcConfig", "srefIxWzskVExpstate");

					if (srefIxWzskVExpstate != oldSrefIxWzskVExpstate) {
						if (srefIxWzskVExpstate == "mind") minimize();
						else if (srefIxWzskVExpstate == "regd") regularize();
					} else {
						refresh();
					};

				} else {
					refresh();
				};
			} else if (blk.nodeName == "DpchEngWzskHwcConfigAlign") {
				handleDpchEngWzskHwcConfigAlign(dom);
			} else if (blk.nodeName == "DpchEngWzskHwcConfigLive") {
				handleDpchEngWzskHwcConfigLive(dom);
			};
		};
	};
};
