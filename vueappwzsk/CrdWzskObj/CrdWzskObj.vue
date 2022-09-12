<template>
	<v-container v-if="initdone">
		<PnlWzskObjList
			v-on:request="handleRequest"
			ref="PnlWzskObjList"
			:scrJref=statshr.scrJrefList
		/>
		<PnlWzskObjRec
			v-on:crdopen="handleCrdopen"
			v-on:request="handleRequest"
			ref="PnlWzskObjRec"
			:scrJref=statshr.scrJrefRec
		/>
	</v-container>
</template>

<script>
	import Wzsk from '../../scripts/Wzsk';

	/*
	*/
	import PnlWzskObjList from './PnlWzskObjList';
	import PnlWzskObjRec from './PnlWzskObjRec';
	/*
	*/

	/*
	<!-- IP import.cust - INSERT -->
	*/

	export default {
		name: 'CrdWzskObj',

		props: {
			scrJref: String
		},

		components: {
			/*
			*/
			PnlWzskObjList,
			PnlWzskObjRec
			/*
			*/
		},

		mounted() {
			//console.log("CrdWzskObj.mounted() with scrJref = " + this.scrJref);

			const dpchapp = {
				"DpchAppWzskInit": {
					"scrJref": this.scrJref
				}
			};

			this.$emit("request", {scrJref: this.scrJref, dpchapp: dpchapp, then: "handleDpchAppInitReply"});
		},

		methods: {
			/*
			<!-- IP cust - INSERT -->
			*/

			mergeDpchEngData: function(dpcheng) {
				/*
				*/
				var dlgopen = false;
				var dlgclose = false;

				var srefDlg = "";
				var scrJrefDlg = "";

				if (dpcheng.ContInfWzskObj) this.continf = dpcheng.ContInfWzskObj;
				if (dpcheng.FeedFSge) this.feedFSge = dpcheng.FeedFSge;
				if (dpcheng.StatAppWzskObj) this.statapp = dpcheng.StatAppWzskObj;
				if (dpcheng.StatShrWzskObj) {
					if (this.statshr != null) {
						dlgopen = (dpcheng.StatShrWzskObj.scrJrefDlgnew != "");
						dlgclose = (this.statshr.scrJrefDlgnew != "");
						if (dlgopen && dlgclose) {
							dlgopen = false;
							dlgclose = false;
						}
						if (dlgopen) {
							if (dpcheng.StatShrWzskObj.scrJrefDlgnew != "") {
								srefDlg = "DlgWzskObjNew";
								scrJrefDlg = dpcheng.StatShrWzskObj.scrJrefDlgnew;
							}
						}
					}
					this.statshr = dpcheng.StatShrWzskObj;
				}
				if (dpcheng.TagWzskObj) {
					Wzsk.unescapeBlock(dpcheng.TagWzskObj);
					this.tag = dpcheng.TagWzskObj;
				}

				if (dlgopen) this.$emit("dlgopen", {srefDlg: srefDlg, scrJrefDlg: scrJrefDlg});
				else if (dlgclose) this.$emit("dlgclose");
				/*
				*/
			},

			handleCrdopen: function(obj) {
				this.$emit("crdopen", obj)
			},

			handleRequest: function(obj) {
				this.$emit("request", obj)
			},

			handleReply: function(obj) {
				if (obj.scrJref == this.scrJref) {
					if (obj.then == "handleDpchAppInitReply") this.handleDpchAppInitReply(obj.dpcheng);

				} else if (this.initdone) {
					/*
					*/
					if (obj.scrJref == this.statshr.scrJrefList) this.$refs.PnlWzskObjList.handleReply(obj);
					else this.$refs.PnlWzskObjRec.handleReply(obj);
					/*
					*/
				}
			},

			handleDpchAppInitReply: function(dpcheng) {
				this.mergeDpchEngData(dpcheng);

				this.initdone = true;
			},

			handleUpdate: function(obj) {
				var processed = false;

				if (obj.dpcheng.scrJref == this.scrJref) {
					if (obj.srefIxWzskVDpch == "DpchEngWzskObjData") this.mergeDpchEngData(obj.dpcheng);
					processed = true;

				} else if (this.initdone) {
					/*
					*/
					if (obj.dpcheng.scrJref == this.statshr.scrJrefList) {
						this.$refs.PnlWzskObjList.handleUpdate(obj);
						processed = true;
					} else processed = this.$refs.PnlWzskObjRec.handleUpdate(obj);
					/*
					*/
				}

				//if (!processed) console.log("got a '" + obj.srefIxWzskVDpch + "' from job with scrJref " + obj.dpcheng.scrJref);

				return processed
			},
		},

		data: () => ({
			initdone: false,

			/*
			*/
			continf: null,

			feedFSge: null,

			statapp: null,

			statshr: null,

			tag: null,
			/*
			*/
			
			/*
			<!-- IP data.cust - INSERT -->
			*/
		})
	}
</script>
