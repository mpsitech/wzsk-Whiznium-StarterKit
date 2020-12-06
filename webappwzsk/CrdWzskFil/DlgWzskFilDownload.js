// IP cust --- INSERT

// --- view initialization and refresh
function init() {
	hdrdoc = doc.getElementById("_hdr").contentDocument;
	contdoc = doc.getElementById("_cont").contentDocument;
	ftrdoc = doc.getElementById("_ftr").contentDocument;

	setTextContent(hdrdoc, hdrdoc.getElementById("Cpt"), retrieveTi(srcdoc, "TagDlgWzskFilDownload", "Cpt"));

	setTextContent(contdoc, contdoc.getElementById("Dld"), retrieveTi(srcdoc, "TagDlgWzskFilDownload", "Dld"));

	setTextContent(ftrdoc, ftrdoc.getElementById("ButDne"), retrieveTi(srcdoc, "TagDlgWzskFilDownload", "ButDne"));

	refresh();
};

function refresh() {
	// IP refresh.vars --- BEGIN

	// IP refresh.vars --- END

	// IP refresh --- BEGIN
	refreshDld(contdoc, "Dld", scrJref, retrieveCi(srcdoc, "ContInfDlgWzskFilDownload", "Dld"), true);

	// IP refresh --- END
};

// --- event handlers
function handleLoad() {
	scrJref = location.search.substr(location.search.indexOf("scrJref=")+8);

	doc = document;
	srcdoc = doc.getElementById("_src").contentDocument;

	var str = serializeDpchApp("DpchAppWzskInit", scrJref);
	sendReq(str, doc, handleDpchAppInitReply, true);
};

// --- specific event handlers for app controls

// --- generalized event handlers for app controls

// --- generalized event handlers for shared controls

function handleButClick(ctlsref) {
	var str = serializeDpchAppDo(srcdoc, "DpchAppDlgWzskFilDownloadDo", scrJref, ctlsref + "Click");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

// --- server interaction
function mergeDpchEngData(dom) {
	var mask = [];

	if (updateSrcblock(dom, "DpchEngDlgWzskFilDownloadData", "ContInfDlgWzskFilDownload", srcdoc)) mask.push("continf");
	if (updateSrcblock(dom, "DpchEngDlgWzskFilDownloadData", "StatAppDlgWzskFilDownload", srcdoc)) mask.push("statapp");
	if (updateSrcblock(dom, "DpchEngDlgWzskFilDownloadData", "TagDlgWzskFilDownload", srcdoc)) mask.push("tag");

	return mask;
};

function handleDpchEng(dom, dpch) {
	if (dpch == "DpchEngDlgWzskFilDownloadData") {
		mergeDpchEngData(dom);
		refresh();
	} else if (dpch == "DpchEngDlgWzskFilDownloadData") {
		handleDpchEngDlgWzskFilDownloadData(dom);
	};
};

function handleDpchEngDlgWzskFilDownloadData(dom) {
	// IP handleDpchEngDlgWzskFilDownloadData --- INSERT
};

function handleDpchAppInitReply() {
	var dom, blk;

	if (doc.req.readyState == 4) {
		dom = doc.req.responseXML;

		blk = retrieveBlock(dom, "//wzsk:*");
		if (blk) {
			if (blk.nodeName == "DpchEngDlgWzskFilDownloadData") {
				mergeDpchEngData(dom);
				init();
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

			} else if (blk.nodeName == "DpchEngWzskAlert") {
				getCrdwnd().showAlr(retrieveValue(dom, "//wzsk:DpchEngWzskAlert/wzsk:scrJref"),
							retrieveBlock(dom, "//wzsk:DpchEngWzskAlert/wzsk:ContInfWzskAlert"),
							retrieveBlock(dom, "//wzsk:DpchEngWzskAlert/wzsk:FeedFMcbAlert"));;

			} else if (blk.nodeName == "DpchEngDlgWzskFilDownloadData") {
				mergeDpchEngData(dom);
				refresh();
			};
		};
	};
};
