// IP cust --- INSERT

// --- expand state management
function minimize() {
	// change container heights
	getCrdwnd().changeHeight("Config", 30);
	doc.getElementById("tdSide").setAttribute("height", "30");
	doc.getElementById("Config_side").setAttribute("height", "30");
	doc.getElementById("Config_cont").setAttribute("height", "30");

	// change content
	doc.getElementById("Config_side").src = "./PnlWzskVtrConfig_aside.html";
	doc.getElementById("Config_cont").src = "./PnlWzskVtrConfig_a.html";
};

function regularize() {
	// change content (container heights in refreshBD)
	doc.getElementById("Config_side").src = "./PnlWzskVtrConfig_bside.html";
	doc.getElementById("Config_cont").src = "./PnlWzskVtrConfig_b.html";
};

// --- view initialization and refresh
function initA() {
	if (!doc) return;

	sidedoc = doc.getElementById("Config_side").contentDocument;
	contdoc = doc.getElementById("Config_cont").contentDocument;
	hdrdoc = null;
	contcontdoc = null;
	ftrdoc = null;

	initCpt(contdoc, "Cpt", retrieveTi(srcdoc, "TagWzskVtrConfig", "Cpt"));

	refreshA();
};

function initBD(bNotD) {
	if (!doc) return;

	sidedoc = doc.getElementById("Config_side").contentDocument;
	contdoc = doc.getElementById("Config_cont").contentDocument;
	hdrdoc = contdoc.getElementById("Config_hdr").contentDocument;
	contcontdoc = contdoc.getElementById("Config_cont").contentDocument;

	// IP initBD --- BEGIN
	initCpt(hdrdoc, "Cpt", retrieveTi(srcdoc, "TagWzskVtrConfig", "Cpt"));
	initCpt(contcontdoc, "HdgPvw", retrieveTi(srcdoc, "TagWzskVtrConfig", "HdgPvw"));
	initCpt(contcontdoc, "CptMde", retrieveTi(srcdoc, "TagWzskVtrConfig", "CptMde"));
	refreshRbu(contcontdoc, srcdoc, "RbuMde", "FeedFRbuMde", retrieveCi(srcdoc, "ContIacWzskVtrConfig", "numFRbuMde"), true);
	initCpt(contcontdoc, "CptAsp", retrieveTi(srcdoc, "TagWzskVtrConfig", "CptAsp"));
	initCpt(contcontdoc, "CptSte", retrieveTi(srcdoc, "TagWzskVtrConfig", "CptSte"));
	initBut(contcontdoc, "ButSta", retrieveTi(srcdoc, "TagWzskVtrConfig", "ButSta"));
	initBut(contcontdoc, "ButSto", retrieveTi(srcdoc, "TagWzskVtrConfig", "ButSto"));
	// IP initBD --- END

	refreshBD(bNotD);
};

function init() {
	var srefIxWzskVExpstate = retrieveSi(srcdoc, "StatShrWzskVtrConfig", "srefIxWzskVExpstate");

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

	var height = 558; // full cont height

	// IP refreshBD.vars --- BEGIN
	var ButClaimActive = (retrieveSi(srcdoc, "StatShrWzskVtrConfig", "ButClaimActive") == "true");

	var CusImgHeight = parseInt(retrieveSi(srcdoc, "StatShrWzskVtrConfig", "CusImgHeight"));

	var ButPlayActive = (retrieveSi(srcdoc, "StatShrWzskVtrConfig", "ButPlayActive") == "true");
	var ButStopActive = (retrieveSi(srcdoc, "StatShrWzskVtrConfig", "ButStopActive") == "true");

	var SldAspActive = (retrieveSi(srcdoc, "StatShrWzskVtrConfig", "SldAspActive") == "true");

	var ButStaActive = (retrieveSi(srcdoc, "StatShrWzskVtrConfig", "ButStaActive") == "true");
	var ButStoActive = (retrieveSi(srcdoc, "StatShrWzskVtrConfig", "ButStoActive") == "true");

	// IP refreshBD.vars --- END

	// IP refreshBD --- BEGIN
	refreshButicon(hdrdoc, "ButClaim", "icon/claim", ButClaimActive, retrieveCi(srcdoc, "ContInfWzskVtrConfig", "ButClaimOn") == "true");

	setRbuValue(contcontdoc, "RbuMde", retrieveCi(srcdoc, "ContIacWzskVtrConfig", "numFRbuMde"), true);

	mytd = contcontdoc.getElementById("tdImg");
	mytd.setAttribute("height", "" + CusImgHeight);
	contcontdoc.getElementById("CusImg").setAttribute("height", "" + CusImgHeight);
	height += CusImgHeight-384;

	refreshButicon(contcontdoc, "ButPlay", "iconwzsk/play", ButPlayActive, false);
	refreshButicon(contcontdoc, "ButStop", "iconwzsk/stop", ButStopActive, false);

	refreshSld(contcontdoc, "SldAsp", true, false, parseFloat(retrieveSi(srcdoc, "StatShrWzskVtrConfig", "SldAspMin")), parseFloat(retrieveSi(srcdoc, "StatShrWzskVtrConfig", "SldAspMax")), parseFloat(retrieveCi(srcdoc, "ContIacWzskVtrConfig", "SldAsp")), SldAspActive, false);

	refreshTxt(contcontdoc, "TxtSte", retrieveCi(srcdoc, "ContInfWzskVtrConfig", "TxtSte"));

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
	var srefIxWzskVExpstate = retrieveSi(srcdoc, "StatShrWzskVtrConfig", "srefIxWzskVExpstate");

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
	var str = serializeDpchAppDo(srcdoc, "DpchAppWzskVtrConfigDo", scrJref, ctlsref + "Click");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

function handleRbuSelect(_doc, ctlsref, num) {
	setCi(srcdoc, "ContIacWzskVtrConfig", "numF" + ctlsref, "" + num);

	var str = serializeDpchAppData(srcdoc, "DpchAppWzskVtrConfigData", scrJref, "ContIacWzskVtrConfig");
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

	if (shr) oldVal = parseFloat(retrieveCi(srcdoc, "ContIacWzskVtrConfig", ctlsref));
	else oldVal = parseFloat(_doc.getElementById(ctlsref + "Val").value);
	min = parseFloat(retrieveSi(srcdoc, "StatShrWzskVtrConfig", ctlsref + "Min"));
	max = parseFloat(retrieveSi(srcdoc, "StatShrWzskVtrConfig", ctlsref + "Max"));

	if (_rast) rast = parseFloat(retrieveSi(srcdoc, "StatShrWzskVtrConfig", ctlsref + "Rast"));

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
		setCi(srcdoc, "ContIacWzskVtrConfig", ctlsref, "" + val);

		var str = serializeDpchAppData(srcdoc, "DpchAppWzskVtrConfigData", scrJref, "ContIacWzskVtrConfig");
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

	if (shr) oldVal = parseFloat(retrieveCi(srcdoc, "ContIacWzskVtrConfig", ctlsref));
	else oldVal = parseFloat(_doc.getElementById(ctlsref + "Val").value);
	min = parseFloat(retrieveSi(srcdoc, "StatShrWzskVtrConfig", ctlsref + "Min"));
	max = parseFloat(retrieveSi(srcdoc, "StatShrWzskVtrConfig", ctlsref + "Max"));

	if (_rast) rast = parseFloat(retrieveSi(srcdoc, "StatShrWzskVtrConfig", ctlsref + "Rast"));

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
		setCi(srcdoc, "ContIacWzskVtrConfig", ctlsref, "" + val);

		var str = serializeDpchAppData(srcdoc, "DpchAppWzskVtrConfigData", scrJref, "ContIacWzskVtrConfig");
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

	min = parseFloat(retrieveSi(srcdoc, "StatShrWzskVtrConfig", ctlsref + "Min"));
	max = parseFloat(retrieveSi(srcdoc, "StatShrWzskVtrConfig", ctlsref + "Max"));

	if (_rast) rast = parseFloat(retrieveSi(srcdoc, "StatShrWzskVtrConfig", ctlsref + "Rast"));
	else rast = 0.0;

	pos = getSldPosFromEvtx(true, evt.clientX);

	if (log) val = getSldLogvalFromPos(min, max, rast, pos);
	else val = getSldValFromPos(min, max, rast, pos);

	setSldPos(_doc, ctlsref, true, pos);
	setSldVal(_doc, ctlsref, val, true, true);

	if (shr) setCi(srcdoc, "ContIacWzskVtrConfig", ctlsref, "" + val);
	else window["handle" + ctlsref + "Change"](val);
};

function handleSldMup(_doc, ctlsref, shr) {
	_doc.getElementById("td" + ctlsref).onmousemove = null;
	_doc.getElementById("td" + ctlsref).onmouseup = null;

	if (shr) {
		var str = serializeDpchAppData(srcdoc, "DpchAppWzskVtrConfigData", scrJref, "ContIacWzskVtrConfig");
		sendReq(str, doc, handleDpchAppDataDoReply);
	};
};

function handleSldValKey(_doc, ctlsref, shr, log, _rast, evt) {
	var elem = _doc.getElementById(ctlsref + "Val");

	var pos, val;

	var min, max, rast;

	elem.setAttribute("class", "txfxsmod");

	if (evt.keyCode == 13) {
		min = parseFloat(retrieveSi(srcdoc, "StatShrWzskVtrConfig", ctlsref + "Min"));
		max = parseFloat(retrieveSi(srcdoc, "StatShrWzskVtrConfig", ctlsref + "Max"));

		if (_rast) rast = parseFloat(retrieveSi(srcdoc, "StatShrWzskVtrConfig", ctlsref + "Rast"));
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
			setCi(srcdoc, "ContIacWzskVtrConfig", ctlsref, "" + val);

			var str = serializeDpchAppData(srcdoc, "DpchAppWzskVtrConfigData", scrJref, "ContIacWzskVtrConfig");
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

	min = parseFloat(retrieveSi(srcdoc, "StatShrWzskVtrConfig", ctlsref + "Min"));
	max = parseFloat(retrieveSi(srcdoc, "StatShrWzskVtrConfig", ctlsref + "Max"));

	if (_rast) rast = parseFloat(retrieveSi(srcdoc, "StatShrWzskVtrConfig", ctlsref + "Rast"));
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
		setCi(srcdoc, "ContIacWzskVtrConfig", ctlsref, "" + val);

		var str = serializeDpchAppData(srcdoc, "DpchAppWzskVtrConfigData", scrJref, "ContIacWzskVtrConfig");
		sendReq(str, doc, handleDpchAppDataDoReply);

	} else {
	window["handle" + ctlsref + "Change"](val);
	};
};

// --- server interaction
function mergeDpchEngData(dom) {
	var mask = [];

	// IP mergeDpchEngData --- BEGIN
	if (updateSrcblock(dom, "DpchEngWzskVtrConfigData", "ContIacWzskVtrConfig", srcdoc)) mask.push("contiac");
	if (updateSrcblock(dom, "DpchEngWzskVtrConfigData", "ContInfWzskVtrConfig", srcdoc)) mask.push("continf");
	if (updateSrcblock(dom, "DpchEngWzskVtrConfigData", "FeedFRbuMde", srcdoc)) mask.push("feedFRbuMde");
	if (updateSrcblock(dom, "DpchEngWzskVtrConfigData", "StatShrWzskVtrConfig", srcdoc)) mask.push("statshr");
	if (updateSrcblock(dom, "DpchEngWzskVtrConfigData", "TagWzskVtrConfig", srcdoc)) mask.push("tag");
	// IP mergeDpchEngData --- END

	return mask;
};

function handleDpchEng(dom, dpch) {
	if (dpch == "DpchEngWzskVtrConfigData") {
		var oldSrefIxWzskVExpstate = retrieveSi(srcdoc, "StatShrWzskVtrConfig", "srefIxWzskVExpstate");

		var mask = mergeDpchEngData(dom);

		if (mask.indexOf("statshr") != -1) {
			var srefIxWzskVExpstate = retrieveSi(srcdoc, "StatShrWzskVtrConfig", "srefIxWzskVExpstate");

			if (srefIxWzskVExpstate != oldSrefIxWzskVExpstate) {
				if (srefIxWzskVExpstate == "mind") minimize();
				else if (srefIxWzskVExpstate == "regd") regularize();
			} else {
				refresh();
			};

		} else {
			refresh();
		};
	} else if (dpch == "DpchEngWzskVtrConfigAlign") {
		handleDpchEngWzskVtrConfigAlign(dom);
	} else if (dpch == "DpchEngWzskVtrConfigLive") {
		handleDpchEngWzskVtrConfigLive(dom);
	};
};

function handleDpchEngWzskVtrConfigAlign(dom) {
	// IP handleDpchEngWzskVtrConfigAlign --- INSERT
};

function handleDpchEngWzskVtrConfigLive(dom) {
	// IP handleDpchEngWzskVtrConfigLive --- INSERT
};

function handleDpchAppInitReply() {
	var dom, blk;

	if (doc.req.readyState == 4) {
		dom = doc.req.responseXML;

		blk = retrieveBlock(dom, "//wzsk:*");
		if (blk) {
			if (blk.nodeName == "DpchEngWzskVtrConfigData") {
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

			} else if (blk.nodeName == "DpchEngWzskVtrConfigData") {
				var oldSrefIxWzskVExpstate = retrieveSi(srcdoc, "StatShrWzskVtrConfig", "srefIxWzskVExpstate");

				var mask = mergeDpchEngData(dom);

				if (mask.indexOf("statshr") != -1) {
					var srefIxWzskVExpstate = retrieveSi(srcdoc, "StatShrWzskVtrConfig", "srefIxWzskVExpstate");

					if (srefIxWzskVExpstate != oldSrefIxWzskVExpstate) {
						if (srefIxWzskVExpstate == "mind") minimize();
						else if (srefIxWzskVExpstate == "regd") regularize();
					} else {
						refresh();
					};

				} else {
					refresh();
				};
			} else if (blk.nodeName == "DpchEngWzskVtrConfigAlign") {
				handleDpchEngWzskVtrConfigAlign(dom);
			} else if (blk.nodeName == "DpchEngWzskVtrConfigLive") {
				handleDpchEngWzskVtrConfigLive(dom);
			};
		};
	};
};
