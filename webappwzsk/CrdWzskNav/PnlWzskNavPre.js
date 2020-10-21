/**
  * \file PnlWzskNavPre.js
  * web client functionality for panel PnlWzskNavPre
  * \author Catherine Johnson
  * \date created: 18 Oct 2020
  * \date modified: 18 Oct 2020
  */

// --- expand state management
function minimize() {
};

function regularize() {
};

// --- view initialization and refresh
function init() {
	if (!doc) return;

	contdoc = doc.getElementById("Pre_cont").contentDocument;

// IP init --- INSERT

	refresh();
};

function refresh() {
	var line;

	var n = 0;

	var TxtObjAvail = (retrieveSi(srcdoc, "StatShrWzskNavPre", "TxtObjAvail") == "true"); if (TxtObjAvail) n++;

	line = contdoc.getElementById("line");
	while (line.firstChild) line.removeChild(line.firstChild);

	var i = 0;

	if (TxtObjAvail) {
		i++;

		line.appendChild(makeImgBut("ButObjRemove", "icon/close"));
		if (i == n) line.appendChild(makeSpanCpt("\u00a0" + retrieveTi(srcdoc,  "TagWzskNavPre", "CptObj") + ": " + retrieveCi(srcdoc, "ContInfWzskNavPre", "TxtObj")));
		else line.appendChild(makeSpanCpt("\u00a0" + retrieveTi(srcdoc, "TagWzskNavPre", "CptObj") + ": " + retrieveCi(srcdoc, "ContInfWzskNavPre", "TxtObj") + ",\u00a0\u00a0"));
	};

};

// --- event handlers
function handleLoad() {
	scrJref = location.search.substr(location.search.indexOf("scrJref=")+8);

	doc = document;
	srcdoc = doc.getElementById("Pre_src").contentDocument;

	var str = serializeDpchApp("DpchAppWzskInit", scrJref);
	sendReq(str, doc, handleDpchAppInitReply, true);
};

function handleButClick(ctlsref) {
	var str = serializeDpchAppDo(srcdoc, "DpchAppWzskNavPreDo", scrJref, ctlsref + "Click");
	sendReq(str, doc, handleDpchAppDoReply);
};

// --- server interaction
function mergeDpchEngData(dom) {
	var mask = [];

	if (updateSrcblock(dom, "DpchEngWzskNavPreData", "ContInfWzskNavPre", srcdoc)) mask.push("continf");
	if (updateSrcblock(dom, "DpchEngWzskNavPreData", "StatShrWzskNavPre", srcdoc)) mask.push("statshr");
	if (updateSrcblock(dom, "DpchEngWzskNavPreData", "TagWzskNavPre", srcdoc)) mask.push("tag");

	return mask;
};

function handleDpchEng(dom, dpch) {
	if (dpch == "DpchEngWzskNavPreData") {
		mergeDpchEngData(dom);
		refresh();
	};
};

function handleDpchAppInitReply() {
	var dom, blk;

	if (doc.req.readyState == 4) {
		dom = doc.req.responseXML;

		blk = retrieveBlock(dom, "//wzsk:*");
		if (blk) {
			if (blk.nodeName == "DpchEngWzskNavPreData") {
				mergeDpchEngData(dom);
				init();

				getCrdwnd().setInitdone("Pre");
			};
		};
	};
};

function handleDpchAppDoReply() {
	var dom, blk;

	if (doc.req.readyState == 4) {
		dom = doc.req.responseXML;

		// check dispatch type
		blk = retrieveBlock(dom, "//wzsk:*");

		if (blk) {
			if (blk.nodeName == "DpchEngWzskConfirm") {
				// do nothing

			} else if (blk.nodeName == "DpchEngWzskNavPreData") {
				mergeDpchEngData(dom);
				refresh();
			};
		};
	};
};

