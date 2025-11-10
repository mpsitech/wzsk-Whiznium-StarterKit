// IP cust --- INSERT

// --- expand state management
function minimize() {
	// change container heights
	getCrdwnd().changeHeight("Rotary", 30);
	doc.getElementById("tdSide").setAttribute("height", "30");
	doc.getElementById("Rotary_side").setAttribute("height", "30");
	doc.getElementById("Rotary_cont").setAttribute("height", "30");

	// change content
	doc.getElementById("Rotary_side").src = "./PnlWzskLlvRotary_aside.html";
	doc.getElementById("Rotary_cont").src = "./PnlWzskLlvRotary_a.html";
};

function regularize() {
	// change content (container heights in refreshBD)
	doc.getElementById("Rotary_side").src = "./PnlWzskLlvRotary_bside.html";
	doc.getElementById("Rotary_cont").src = "./PnlWzskLlvRotary_b.html";
};

// --- view initialization and refresh
function initA() {
	if (!doc) return;

	sidedoc = doc.getElementById("Rotary_side").contentDocument;
	contdoc = doc.getElementById("Rotary_cont").contentDocument;
	hdrdoc = null;
	contcontdoc = null;
	ftrdoc = null;

	initCpt(contdoc, "Cpt", retrieveTi(srcdoc, "TagWzskLlvRotary", "Cpt"));

	refreshA();
};

function initBD(bNotD) {
	if (!doc) return;

	sidedoc = doc.getElementById("Rotary_side").contentDocument;
	contdoc = doc.getElementById("Rotary_cont").contentDocument;
	hdrdoc = contdoc.getElementById("Rotary_hdr").contentDocument;
	contcontdoc = contdoc.getElementById("Rotary_cont").contentDocument;

	// IP initBD --- BEGIN
	initCpt(hdrdoc, "Cpt", retrieveTi(srcdoc, "TagWzskLlvRotary", "Cpt"));
	initCpt(contcontdoc, "CptTrg", retrieveTi(srcdoc, "TagWzskLlvRotary", "CptTrg"));
	// IP initBD --- END

	refreshBD(bNotD);
};

function init() {
	var srefIxWzskVExpstate = retrieveSi(srcdoc, "StatShrWzskLlvRotary", "srefIxWzskVExpstate");

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

	var height = 35; // full cont height

	// IP refreshBD.vars --- BEGIN
	var ButClaimActive = (retrieveSi(srcdoc, "StatShrWzskLlvRotary", "ButClaimActive") == "true");
	var SldTrgActive = (retrieveSi(srcdoc, "StatShrWzskLlvRotary", "SldTrgActive") == "true");

	// IP refreshBD.vars --- END

	// IP refreshBD --- BEGIN
	refreshButicon(hdrdoc, "ButClaim", "icon/claim", ButClaimActive, retrieveCi(srcdoc, "ContInfWzskLlvRotary", "ButClaimOn") == "true");
	refreshSld(contcontdoc, "SldTrg", true, false, parseFloat(retrieveSi(srcdoc, "StatShrWzskLlvRotary", "SldTrgMin")), parseFloat(retrieveSi(srcdoc, "StatShrWzskLlvRotary", "SldTrgMax")), parseFloat(retrieveCi(srcdoc, "ContIacWzskLlvRotary", "SldTrg")), SldTrgActive, false);

	// IP refreshBD --- END

	getCrdwnd().changeHeight("Rotary", height+31);
	doc.getElementById("tdSide").setAttribute("height", "" + (height+31));
	doc.getElementById("Rotary_side").setAttribute("height", "" + (height+31));
	doc.getElementById("Rotary_cont").setAttribute("height", "" + (height+31));
	sidedoc.getElementById("tdFlex").setAttribute("height", "" + (height+31-30));
	contdoc.getElementById("tdCont").setAttribute("height", "" + height);
	contdoc.getElementById("Rotary_cont").setAttribute("height", "" + height);
};

function refresh() {
	var srefIxWzskVExpstate = retrieveSi(srcdoc, "StatShrWzskLlvRotary", "srefIxWzskVExpstate");

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
	srcdoc = doc.getElementById("Rotary_src").contentDocument;

	var str = serializeDpchApp("DpchAppWzskInit", scrJref);
	sendReq(str, doc, handleDpchAppInitReply, true);
};

// --- specific event handlers for app controls

// --- generalized event handlers for app controls

// --- generalized event handlers for shared controls

function handleButClick(ctlsref) {
	var str = serializeDpchAppDo(srcdoc, "DpchAppWzskLlvRotaryDo", scrJref, ctlsref + "Click");
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

	if (shr) oldVal = parseFloat(retrieveCi(srcdoc, "ContIacWzskLlvRotary", ctlsref));
	else oldVal = parseFloat(_doc.getElementById(ctlsref + "Val").value);
	min = parseFloat(retrieveSi(srcdoc, "StatShrWzskLlvRotary", ctlsref + "Min"));
	max = parseFloat(retrieveSi(srcdoc, "StatShrWzskLlvRotary", ctlsref + "Max"));

	if (_rast) rast = parseFloat(retrieveSi(srcdoc, "StatShrWzskLlvRotary", ctlsref + "Rast"));

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
		setCi(srcdoc, "ContIacWzskLlvRotary", ctlsref, "" + val);

		var str = serializeDpchAppData(srcdoc, "DpchAppWzskLlvRotaryData", scrJref, "ContIacWzskLlvRotary");
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

	if (shr) oldVal = parseFloat(retrieveCi(srcdoc, "ContIacWzskLlvRotary", ctlsref));
	else oldVal = parseFloat(_doc.getElementById(ctlsref + "Val").value);
	min = parseFloat(retrieveSi(srcdoc, "StatShrWzskLlvRotary", ctlsref + "Min"));
	max = parseFloat(retrieveSi(srcdoc, "StatShrWzskLlvRotary", ctlsref + "Max"));

	if (_rast) rast = parseFloat(retrieveSi(srcdoc, "StatShrWzskLlvRotary", ctlsref + "Rast"));

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
		setCi(srcdoc, "ContIacWzskLlvRotary", ctlsref, "" + val);

		var str = serializeDpchAppData(srcdoc, "DpchAppWzskLlvRotaryData", scrJref, "ContIacWzskLlvRotary");
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

	min = parseFloat(retrieveSi(srcdoc, "StatShrWzskLlvRotary", ctlsref + "Min"));
	max = parseFloat(retrieveSi(srcdoc, "StatShrWzskLlvRotary", ctlsref + "Max"));

	if (_rast) rast = parseFloat(retrieveSi(srcdoc, "StatShrWzskLlvRotary", ctlsref + "Rast"));
	else rast = 0.0;

	pos = getSldPosFromEvtx(true, evt.clientX);

	if (log) val = getSldLogvalFromPos(min, max, rast, pos);
	else val = getSldValFromPos(min, max, rast, pos);

	setSldPos(_doc, ctlsref, true, pos);
	setSldVal(_doc, ctlsref, val, true, true);

	if (shr) setCi(srcdoc, "ContIacWzskLlvRotary", ctlsref, "" + val);
	else window["handle" + ctlsref + "Change"](val);
};

function handleSldMup(_doc, ctlsref, shr) {
	_doc.getElementById("td" + ctlsref).onmousemove = null;
	_doc.getElementById("td" + ctlsref).onmouseup = null;

	if (shr) {
		var str = serializeDpchAppData(srcdoc, "DpchAppWzskLlvRotaryData", scrJref, "ContIacWzskLlvRotary");
		sendReq(str, doc, handleDpchAppDataDoReply);
	};
};

function handleSldValKey(_doc, ctlsref, shr, log, _rast, evt) {
	var elem = _doc.getElementById(ctlsref + "Val");

	var pos, val;

	var min, max, rast;

	elem.setAttribute("class", "txfxsmod");

	if (evt.keyCode == 13) {
		min = parseFloat(retrieveSi(srcdoc, "StatShrWzskLlvRotary", ctlsref + "Min"));
		max = parseFloat(retrieveSi(srcdoc, "StatShrWzskLlvRotary", ctlsref + "Max"));

		if (_rast) rast = parseFloat(retrieveSi(srcdoc, "StatShrWzskLlvRotary", ctlsref + "Rast"));
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
			setCi(srcdoc, "ContIacWzskLlvRotary", ctlsref, "" + val);

			var str = serializeDpchAppData(srcdoc, "DpchAppWzskLlvRotaryData", scrJref, "ContIacWzskLlvRotary");
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

	min = parseFloat(retrieveSi(srcdoc, "StatShrWzskLlvRotary", ctlsref + "Min"));
	max = parseFloat(retrieveSi(srcdoc, "StatShrWzskLlvRotary", ctlsref + "Max"));

	if (_rast) rast = parseFloat(retrieveSi(srcdoc, "StatShrWzskLlvRotary", ctlsref + "Rast"));
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
		setCi(srcdoc, "ContIacWzskLlvRotary", ctlsref, "" + val);

		var str = serializeDpchAppData(srcdoc, "DpchAppWzskLlvRotaryData", scrJref, "ContIacWzskLlvRotary");
		sendReq(str, doc, handleDpchAppDataDoReply);

	} else {
	window["handle" + ctlsref + "Change"](val);
	};
};

// --- server interaction
function mergeDpchEngData(dom) {
	var mask = [];

	// IP mergeDpchEngData --- BEGIN
	if (updateSrcblock(dom, "DpchEngWzskLlvRotaryData", "ContIacWzskLlvRotary", srcdoc)) mask.push("contiac");
	if (updateSrcblock(dom, "DpchEngWzskLlvRotaryData", "ContInfWzskLlvRotary", srcdoc)) mask.push("continf");
	if (updateSrcblock(dom, "DpchEngWzskLlvRotaryData", "StatShrWzskLlvRotary", srcdoc)) mask.push("statshr");
	if (updateSrcblock(dom, "DpchEngWzskLlvRotaryData", "TagWzskLlvRotary", srcdoc)) mask.push("tag");
	// IP mergeDpchEngData --- END

	return mask;
};

function handleDpchEng(dom, dpch) {
	if (dpch == "DpchEngWzskLlvRotaryData") {
		var oldSrefIxWzskVExpstate = retrieveSi(srcdoc, "StatShrWzskLlvRotary", "srefIxWzskVExpstate");

		var mask = mergeDpchEngData(dom);

		if (mask.indexOf("statshr") != -1) {
			var srefIxWzskVExpstate = retrieveSi(srcdoc, "StatShrWzskLlvRotary", "srefIxWzskVExpstate");

			if (srefIxWzskVExpstate != oldSrefIxWzskVExpstate) {
				if (srefIxWzskVExpstate == "mind") minimize();
				else if (srefIxWzskVExpstate == "regd") regularize();
			} else {
				refresh();
			};

		} else {
			refresh();
		};
	};
};

function handleDpchAppInitReply() {
	var dom, blk;

	if (doc.req.readyState == 4) {
		dom = doc.req.responseXML;

		blk = retrieveBlock(dom, "//wzsk:*");
		if (blk) {
			if (blk.nodeName == "DpchEngWzskLlvRotaryData") {
				mergeDpchEngData(dom);
				init();

				getCrdwnd().setInitdone("Rotary");
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

			} else if (blk.nodeName == "DpchEngWzskLlvRotaryData") {
				var oldSrefIxWzskVExpstate = retrieveSi(srcdoc, "StatShrWzskLlvRotary", "srefIxWzskVExpstate");

				var mask = mergeDpchEngData(dom);

				if (mask.indexOf("statshr") != -1) {
					var srefIxWzskVExpstate = retrieveSi(srcdoc, "StatShrWzskLlvRotary", "srefIxWzskVExpstate");

					if (srefIxWzskVExpstate != oldSrefIxWzskVExpstate) {
						if (srefIxWzskVExpstate == "mind") minimize();
						else if (srefIxWzskVExpstate == "regd") regularize();
					} else {
						refresh();
					};

				} else {
					refresh();
				};
			};
		};
	};
};
